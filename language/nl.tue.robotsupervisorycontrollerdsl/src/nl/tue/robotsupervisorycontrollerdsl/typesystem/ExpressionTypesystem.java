package nl.tue.robotsupervisorycontrollerdsl.typesystem;


import org.eclipse.emf.ecore.EObject;

import nl.tue.robotsupervisorycontrollerdsl.generator.common.util.ModelHelper;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Access;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.AccessType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.AccessibleItem;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Action;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.And;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ArrayDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Atom;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.BooleanDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.CommunicationType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ComplexDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ComplexDataTypeReference;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Component;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.DataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Divide;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.DoubleDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.EnumDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.EnumValue;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Equation;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.FeedbackResultType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.GreaterThan;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.GreaterThanEqual;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Implies;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.IntegerDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Literal;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.LiteralBoolean;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.LiteralDouble;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.LiteralInt;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.LiteralString;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Message;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Minus;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Multiply;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Negation;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Negative;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.NoneDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ObjectDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ObjectProperty;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ObjectValue;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Or;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Parenthesized;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Plus;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ResponseResultType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.ResultTransition;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Service;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.SimpleAtom;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.SmallerThan;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.SmallerThanEqual;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.State;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.StringDataType;
import nl.tue.robotsupervisorycontrollerdsl.robotSupervisoryControllerDSL.Variable;

public class ExpressionTypesystem {
	public TypesystemDataType<?> typeOf(EObject expression) {
		if (expression instanceof Or || expression instanceof Implies || expression instanceof And
				|| expression instanceof Equation || expression instanceof GreaterThan
				|| expression instanceof SmallerThan || expression instanceof GreaterThanEqual
				|| expression instanceof SmallerThanEqual) {
			return TypesystemDataType.BOOLEAN;
		} else if (expression instanceof Negation) {
			return typeOf(((Negation) expression).getValue());
		} else if (expression instanceof Negative) {
			return typeOf(((Negative) expression).getValue());
		} else if (expression instanceof Parenthesized) {
			return typeOf(((Parenthesized) expression).getValue());
		} else if (expression instanceof Atom) {
			return simpleType(((Atom) expression).getValue());
		} else if (expression instanceof Access) {
			return accessType(((Access) expression));
		} else if (expression instanceof DataType) {
			return dataType(((DataType) expression));
		} else  if (expression instanceof Multiply) {
			Multiply entity = (Multiply) expression;
			
			if (typeOf(entity.getLeft()) == TypesystemDataType.DOUBLE || typeOf(entity.getRight()) == TypesystemDataType.DOUBLE) {
				return TypesystemDataType.DOUBLE;
			} else {
				return TypesystemDataType.INT;
			}
		} else if (expression instanceof Divide) {
			return TypesystemDataType.DOUBLE;
		} else if (expression instanceof Plus) {
			Plus entity = (Plus) expression;
			
			if (typeOf(entity.getLeft()) == TypesystemDataType.DOUBLE || typeOf(entity.getRight()) == TypesystemDataType.DOUBLE) {
				return TypesystemDataType.DOUBLE;
			} else {
				return TypesystemDataType.INT;
			}
		} else if (expression instanceof Minus) {
			Minus entity = (Minus) expression;
			
			if (typeOf(entity.getLeft()) == TypesystemDataType.DOUBLE || typeOf(entity.getRight()) == TypesystemDataType.DOUBLE) {
				return TypesystemDataType.DOUBLE;
			} else {
				return TypesystemDataType.INT;
			}
		} else if (expression instanceof ComplexDataType) {
			ComplexDataType complex = (ComplexDataType) expression;
			
			if (complex instanceof EnumDataType) {
				return new TypesystemDataType<EnumDataType>(EnumDataType.class, complex, complex.getName());
			} else if (complex instanceof ObjectDataType) {
				return new TypesystemDataType<ObjectDataType>(ObjectDataType.class, null, complex.getName());
			}
		} else if (expression instanceof ObjectValue) {
			return new TypesystemDataType<ObjectDataType>(ObjectDataType.class, null, "object");
		} else if (expression instanceof ObjectProperty) {
			return dataType(((ObjectProperty) expression).getType());
		} else if (expression instanceof Variable) {
			return dataType(((Variable) expression).getType());
		} else if (expression instanceof Literal) {
			return simpleType((Literal) expression);
		}
		
		return TypesystemDataType.UNKNOWN;
	}
	
	public TypesystemDataType<?> simpleType(SimpleAtom atom) {
		if (atom instanceof LiteralInt) {
			return TypesystemDataType.INT;
		} else if (atom instanceof LiteralBoolean) {
			return TypesystemDataType.BOOLEAN;
		} else if (atom instanceof LiteralDouble) {
			return TypesystemDataType.DOUBLE;
		} else if (atom instanceof LiteralString) {
			return TypesystemDataType.STRING;
		} else if (atom instanceof Access) {
			return accessType(((Access) atom));
		}
		
		return TypesystemDataType.UNKNOWN;		
	}
	
	public TypesystemDataType<?> accessType(Access access) {
		AccessibleItem first = access.getFirstItem();
		
		if (first instanceof EnumValue) {
			EnumDataType parentEnum = ModelHelper.findParentOfType(first, EnumDataType.class);
			
			return typeOf(parentEnum);
		} else if (first instanceof Variable) {
			return typeOf(((Variable) first).getType());
		} else if (first instanceof Component || access.getValue() != null) {
			AccessType last = !access.getTypes().isEmpty() ? access.getTypes().get(access.getTypes().size() - 1) : null;
			
			if (last != null && last.getItem() != null) {
				AccessibleItem lastAccessibleItem = last.getItem();
				
				if (lastAccessibleItem instanceof State) {
					return TypesystemDataType.BOOLEAN;
				} else if (lastAccessibleItem instanceof Variable) {
					return typeOf(((Variable) lastAccessibleItem).getType());
				} else if (lastAccessibleItem instanceof ObjectProperty) {
					return typeOf(((ObjectProperty) lastAccessibleItem).getType());
				}
			} else if (last != null && last.getItem() == null) {			
				int unwrap = 0;
				
				for (int i = access.getTypes().size() - 1; i >= 0; i--) {
					AccessType type = access.getTypes().get(i);
					
					if (type.getItem() != null) {
						AccessibleItem currentItem = type.getItem();
						
						if (currentItem instanceof ObjectProperty) {
							ObjectProperty property = (ObjectProperty) currentItem;
							DataType currentDataType = property.getType();
							
							for (int j = 0; j < unwrap; j++) {
								if (currentDataType instanceof ArrayDataType) {
									ArrayDataType array = (ArrayDataType) currentDataType;
									
									currentDataType = array.getType();
								}
							}
							
							return typeOf(currentDataType);
						}
						
						return typeOf(currentItem);
					} else {
						unwrap += 1;
					}
				}
				
				if (first != null) {
					return typeOf(first);
				} else {
					DataType dataType = findValueDataType(access);
					
					return typeOf(dataType);
		
				}
			} else if (last == null && access.getValue() != null) {
				DataType dataType = findValueDataType(access);
				
				return typeOf(dataType);
			}
		}
		
		return TypesystemDataType.UNKNOWN;	
	}

	private DataType findValueDataType(Access access) {
		EnumDataType parentEnum = ModelHelper.findParentOfType(access, EnumDataType.class);
		ResultTransition parentResultTransition = ModelHelper.findParentOfType(access, ResultTransition.class);
		
		if (parentEnum != null) {
			return parentEnum.getType();
		} else if (parentResultTransition != null) {
			CommunicationType communicationType = parentResultTransition.getCommunicationType();
			DataType dataType = null;
			
			if (communicationType instanceof Message) {
				if (parentResultTransition.getResultType() instanceof ResponseResultType) {
					dataType = ((Message) communicationType).getType();
				}
			} else if (communicationType instanceof Service) {
				if (parentResultTransition.getResultType() instanceof ResponseResultType) {
					dataType = ((Service) communicationType).getResponseType();
				}
			} else if (communicationType instanceof Action) {
				if (parentResultTransition.getResultType() instanceof FeedbackResultType) {
					dataType = ((Action) communicationType).getFeedbackType();
				}
	
				if (parentResultTransition.getResultType() instanceof ResponseResultType) {
					dataType = ((Action) communicationType).getResponseType();
				}
			}
	
			return dataType;
		}
		
		return null;
	}
	
	public TypesystemDataType<?> dataType(DataType type) {
		if (type instanceof IntegerDataType) {
			return TypesystemDataType.INT;
		} else if (type instanceof BooleanDataType) {
			return TypesystemDataType.BOOLEAN;
		} else if (type instanceof DoubleDataType) {
			return TypesystemDataType.DOUBLE;
		} else if (type instanceof StringDataType) {
			return TypesystemDataType.STRING;
		} else if (type instanceof NoneDataType) {
			return TypesystemDataType.NONE;
		} else if (type instanceof ArrayDataType) {
			return new TypesystemDataType<>(ArrayDataType.class, ((ArrayDataType) type).getType().getClass(), "array");
		} else if (type instanceof ComplexDataTypeReference) {
			return typeOf(((ComplexDataTypeReference) type).getType());
		}
		
		return TypesystemDataType.UNKNOWN;		
	}
}
