# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vehicle_msgs:msg/VehicleParam.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VehicleParam(type):
    """Metaclass of message 'VehicleParam'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('vehicle_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'vehicle_msgs.msg.VehicleParam')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle_param
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle_param
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle_param
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle_param
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle_param

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VehicleParam(metaclass=Metaclass_VehicleParam):
    """Message class 'VehicleParam'."""

    __slots__ = [
        '_width',
        '_length',
        '_wheel_base',
        '_front_suspension',
        '_rear_suspension',
        '_max_steering_angle',
        '_d_cr',
        '_max_longitudinal_acc',
        '_max_lateral_acc',
    ]

    _fields_and_field_types = {
        'width': 'float',
        'length': 'float',
        'wheel_base': 'float',
        'front_suspension': 'float',
        'rear_suspension': 'float',
        'max_steering_angle': 'float',
        'd_cr': 'float',
        'max_longitudinal_acc': 'float',
        'max_lateral_acc': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.width = kwargs.get('width', float())
        self.length = kwargs.get('length', float())
        self.wheel_base = kwargs.get('wheel_base', float())
        self.front_suspension = kwargs.get('front_suspension', float())
        self.rear_suspension = kwargs.get('rear_suspension', float())
        self.max_steering_angle = kwargs.get('max_steering_angle', float())
        self.d_cr = kwargs.get('d_cr', float())
        self.max_longitudinal_acc = kwargs.get('max_longitudinal_acc', float())
        self.max_lateral_acc = kwargs.get('max_lateral_acc', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.width != other.width:
            return False
        if self.length != other.length:
            return False
        if self.wheel_base != other.wheel_base:
            return False
        if self.front_suspension != other.front_suspension:
            return False
        if self.rear_suspension != other.rear_suspension:
            return False
        if self.max_steering_angle != other.max_steering_angle:
            return False
        if self.d_cr != other.d_cr:
            return False
        if self.max_longitudinal_acc != other.max_longitudinal_acc:
            return False
        if self.max_lateral_acc != other.max_lateral_acc:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def width(self):
        """Message field 'width'."""
        return self._width

    @width.setter
    def width(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'width' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'width' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._width = value

    @builtins.property
    def length(self):
        """Message field 'length'."""
        return self._length

    @length.setter
    def length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'length' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'length' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._length = value

    @builtins.property
    def wheel_base(self):
        """Message field 'wheel_base'."""
        return self._wheel_base

    @wheel_base.setter
    def wheel_base(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'wheel_base' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'wheel_base' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._wheel_base = value

    @builtins.property
    def front_suspension(self):
        """Message field 'front_suspension'."""
        return self._front_suspension

    @front_suspension.setter
    def front_suspension(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'front_suspension' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'front_suspension' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._front_suspension = value

    @builtins.property
    def rear_suspension(self):
        """Message field 'rear_suspension'."""
        return self._rear_suspension

    @rear_suspension.setter
    def rear_suspension(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rear_suspension' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rear_suspension' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rear_suspension = value

    @builtins.property
    def max_steering_angle(self):
        """Message field 'max_steering_angle'."""
        return self._max_steering_angle

    @max_steering_angle.setter
    def max_steering_angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_steering_angle' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_steering_angle' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_steering_angle = value

    @builtins.property
    def d_cr(self):
        """Message field 'd_cr'."""
        return self._d_cr

    @d_cr.setter
    def d_cr(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'd_cr' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'd_cr' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._d_cr = value

    @builtins.property
    def max_longitudinal_acc(self):
        """Message field 'max_longitudinal_acc'."""
        return self._max_longitudinal_acc

    @max_longitudinal_acc.setter
    def max_longitudinal_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_longitudinal_acc' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_longitudinal_acc' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_longitudinal_acc = value

    @builtins.property
    def max_lateral_acc(self):
        """Message field 'max_lateral_acc'."""
        return self._max_lateral_acc

    @max_lateral_acc.setter
    def max_lateral_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_lateral_acc' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_lateral_acc' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_lateral_acc = value
