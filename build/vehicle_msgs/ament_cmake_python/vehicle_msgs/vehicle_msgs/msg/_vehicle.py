# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vehicle_msgs:msg/Vehicle.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Vehicle(type):
    """Metaclass of message 'Vehicle'."""

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
                'vehicle_msgs.msg.Vehicle')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from std_msgs.msg import Int32
            if Int32.__class__._TYPE_SUPPORT is None:
                Int32.__class__.__import_type_support__()

            from std_msgs.msg import String
            if String.__class__._TYPE_SUPPORT is None:
                String.__class__.__import_type_support__()

            from vehicle_msgs.msg import State
            if State.__class__._TYPE_SUPPORT is None:
                State.__class__.__import_type_support__()

            from vehicle_msgs.msg import VehicleParam
            if VehicleParam.__class__._TYPE_SUPPORT is None:
                VehicleParam.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Vehicle(metaclass=Metaclass_Vehicle):
    """Message class 'Vehicle'."""

    __slots__ = [
        '_header',
        '_id',
        '_subclass',
        '_type',
        '_param',
        '_state',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'id': 'std_msgs/Int32',
        'subclass': 'std_msgs/String',
        'type': 'std_msgs/String',
        'param': 'vehicle_msgs/VehicleParam',
        'state': 'vehicle_msgs/State',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'String'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vehicle_msgs', 'msg'], 'VehicleParam'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['vehicle_msgs', 'msg'], 'State'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from std_msgs.msg import Int32
        self.id = kwargs.get('id', Int32())
        from std_msgs.msg import String
        self.subclass = kwargs.get('subclass', String())
        from std_msgs.msg import String
        self.type = kwargs.get('type', String())
        from vehicle_msgs.msg import VehicleParam
        self.param = kwargs.get('param', VehicleParam())
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
        if self.id != other.id:
            return False
        if self.subclass != other.subclass:
            return False
        if self.type != other.type:
            return False
        if self.param != other.param:
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

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if __debug__:
            from std_msgs.msg import Int32
            assert \
                isinstance(value, Int32), \
                "The 'id' field must be a sub message of type 'Int32'"
        self._id = value

    @builtins.property
    def subclass(self):
        """Message field 'subclass'."""
        return self._subclass

    @subclass.setter
    def subclass(self, value):
        if __debug__:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'subclass' field must be a sub message of type 'String'"
        self._subclass = value

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            from std_msgs.msg import String
            assert \
                isinstance(value, String), \
                "The 'type' field must be a sub message of type 'String'"
        self._type = value

    @builtins.property
    def param(self):
        """Message field 'param'."""
        return self._param

    @param.setter
    def param(self, value):
        if __debug__:
            from vehicle_msgs.msg import VehicleParam
            assert \
                isinstance(value, VehicleParam), \
                "The 'param' field must be a sub message of type 'VehicleParam'"
        self._param = value

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
