import * as vscode from 'vscode';
import * as path from 'path';
import { LanguageClient, LanguageClientOptions, ServerOptions, Trace } from 'vscode-languageclient/node';
import { startListener } from './ros-listener';

export function activate(context: vscode.ExtensionContext) {
    const executable = process.platform === 'win32' ? 'nl.tue.robotsupervisorycontrollerdsl.ide.bat' : 'nl.tue.robotsupervisorycontrollerdsl.ide';
    const languageServerPath = path.join('server', 'nl.tue.robotsupervisorycontrollerdsl.ide', 'bin', executable);
    const script = context.asAbsolutePath(languageServerPath);

    const serverOptions: ServerOptions = {
        run: {
            command: script,
        },
        debug: {
            command: script,
        }
    };

    let clientOptions: LanguageClientOptions = {
        documentSelector: ['rscd'],
        synchronize: {
            fileEvents: vscode.workspace.createFileSystemWatcher('**/*.*')
        }
    };

    const languageClient = new LanguageClient('Xtext Server', serverOptions, clientOptions);
    languageClient.trace = Trace.Verbose;
    languageClient.start();

    let currentPanel: vscode.WebviewPanel|undefined;

    // Add visualization command
    context.subscriptions.push(
        vscode.commands.registerCommand('rscd.visualizeController', async () => {
            const column = vscode.window.activeTextEditor
                ? vscode.window.activeTextEditor.viewColumn
                : undefined;

            // If we already have a panel, show it.
            if (currentPanel) {
                currentPanel.reveal(column);
                return;
            }

            // Create and show a new webview
            currentPanel = vscode.window.createWebviewPanel(
                'rscdControllerVisualization',
                'Controller Visualization',
                column || vscode.ViewColumn.One,
                {
                    enableScripts: true,
                    localResourceRoots: [vscode.Uri.joinPath(context.extensionUri, 'visualization')],
                }
            );

            currentPanel.onDidDispose(
                () => {
                    currentPanel = undefined;
                },
                null,
                context.subscriptions
              );

            currentPanel.webview.html = getWebviewContent(currentPanel.webview, context);
            
            startListener(() => currentPanel.webview)
                .then(ros => context.subscriptions.push(vscode.Disposable.from({
                    dispose: async () => await ros.shutdown(),
                })));
        })
    );

    return languageClient;
}

function getWebviewContent(webview: vscode.Webview, context: vscode.ExtensionContext) {
    const scriptPath = webview.asWebviewUri(
        vscode.Uri.joinPath(context.extensionUri, 'visualization', 'dist', 'main.js')
    );

    return `<!doctype html>
    <html>
        <head>
            <meta http-equiv="Content-Security-Policy" content="default-src 'none';  img-src ${webview.cspSource} https:; script-src 'unsafe-eval' ${webview.cspSource}; style-src 'unsafe-inline' ${webview.cspSource};">
        </head>
        <body>
            <div id="root">Connecting to controller...</div>
            <script src="${scriptPath}" type="text/javascript"></script>
        </body>
    </html>`;
}