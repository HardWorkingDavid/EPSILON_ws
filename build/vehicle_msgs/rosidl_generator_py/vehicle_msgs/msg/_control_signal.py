# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vehicle_msgs:msg/ControlSignal.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ControlSignal(type):
    """Metaclass of message 'ControlSignal'."""

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
                'vehicle_msgs.msg.ControlSignal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__control_signal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__control_signal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__control_signal
            cls._TYPE_SUPPORT = module.type_support_msg__msg__control_signal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__control_signal

            from std_msgs.msg import Bool
            if Bool.__class__._TYPE_SUPPORT is None:
                Bool.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from vehicle_msgs.msg import State
            if State.__class__._TYPE_SUPPORT is None:
                State.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ControlSignal(metaclass=Metaclass_ControlSignal):
    """Message class 'ControlSignal'."""

    __slots__ = [
        '_header',
        '_acc',
        '_steer_rate',
        '_is_openloop',
        '_state',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'acc': 'double',
        'steer_rate': 'double',
        'is_openloop': 'std_msgs/Bool',
        'state': 'vehicle_msgs/State',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Bool'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vehicle_msgs', 'msg'], 'State'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.acc = kwargs.get('acc', float())
        self.steer_rate = kwargs.get('steer_rate', float())
        from std_msgs.msg import Bool
        self.is_openloop = kwargs.get('is_openloop', Bool())
        from vehicle_msgs.msg import State
        self.state = kwargs.get('state', State())

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
        if self.header != other.header:
            return False
        if self.acc != other.acc:
            return False
        if self.steer_rate != other.steer_rate:
            return False
        if self.is_openloop != other.is_openloop:
            return False
        if self.state != other.state:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def acc(self):
        """Message field 'acc'."""
        return self._acc

    @acc.setter
    def acc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'acc' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'acc' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._acc = value

    @builtins.property
    def steer_rate(self):
        """Message field 'steer_rate'."""
        return self._steer_rate

    @steer_rate.setter
    def steer_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steer_rate' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steer_rate' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steer_rate = value

    @builtins.property
    def is_openloop(self):
        """Message field 'is_openloop'."""
        return self._is_openloop

    @is_openloop.setter
    def is_openloop(self, value):
        if __debug__:
            from std_msgs.msg import Bool
            assert \
                isinstance(value, Bool), \
                "The 'is_openloop' field must be a sub message of type 'Bool'"
        self._is_openloop = value

    @builtins.property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if __debug__:
            from vehicle_msgs.msg import State
            assert \
                isinstance(value, State), \
                "The 'state' field must be a sub message of type 'State'"
        self._state = value
