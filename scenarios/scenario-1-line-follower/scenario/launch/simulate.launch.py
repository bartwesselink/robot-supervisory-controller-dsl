#!/usr/bin/env python3
# Based on Gazebo Empty World launch file
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gzserver.launch.py')
            ),
            launch_arguments={'world': os.path.join(get_package_share_directory('scenario'), 'worlds', 'lines.world')}.items(),
        ),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gzclient.launch.py')
            ),
        ),

        ExecuteProcess(
            cmd=['ros2', 'param', 'set', '/gazebo', 'use_sim_time', use_sim_time],
            output='screen'),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(get_package_share_directory('turtlebot3_gazebo'), 'launch'), '/robot_state_publisher.launch.py']),
            launch_arguments={'use_sim_time': True}.items(),
        ),

        Node(
            package='emergency_stop',
            namespace='emergency_stop',
            executable='interface',
            name='emergency_stop'
        ),

        Node(
            package='line_detector',
            namespace='line_detector',
            executable='interface',
            name='line_detector'
        ),

        Node(
            package='controller',
            namespace='controller',
            executable='interface',
            name='controller'
        ),
    ])