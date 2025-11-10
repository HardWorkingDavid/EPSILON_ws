# generated from rosidl_generator_py/resource/_idl.py.em
# with input from vehicle_msgs:msg/Lane.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'child_id'
# Member 'father_id'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Lane(type):
    """Metaclass of message 'Lane'."""

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
                'vehicle_msgs.msg.Lane')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__lane
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__lane
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__lane
            cls._TYPE_SUPPORT = module.type_support_msg__msg__lane
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__lane

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Lane(metaclass=Metaclass_Lane):
    """Message class 'Lane'."""

    __slots__ = [
        '_header',
        '_id',
        '_dir',
        '_child_id',
        '_father_id',
        '_l_lane_id',
        '_l_change_avbl',
        '_r_lane_id',
        '_r_change_avbl',
        '_behavior',
        '_length',
        '_start_point',
        '_final_point',
        '_points',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'id': 'int32',
        'dir': 'int32',
        'child_id': 'sequence<int32>',
        'father_id': 'sequence<int32>',
        'l_lane_id': 'int32',
        'l_change_avbl': 'boolean',
        'r_lane_id': 'int32',
        'r_change_avbl': 'boolean',
        'behavior': 'string',
        'length': 'float',
        'start_point': 'geometry_msgs/Point',
        'final_point': 'geometry_msgs/Point',
        'points': 'sequence<geometry_msgs/Point>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.id = kwargs.get('id', int())
        self.dir = kwargs.get('dir', int())
        self.child_id = array.array('i', kwargs.get('child_id', []))
        self.father_id = array.array('i', kwargs.get('father_id', []))
        self.l_lane_id = kwargs.get('l_lane_id', int())
        self.l_change_avbl = kwargs.get('l_change_avbl', bool())
        self.r_lane_id = kwargs.get('r_lane_id', int())
        self.r_change_avbl = kwargs.get('r_change_avbl', bool())
        self.behavior = kwargs.get('behavior', str())
        self.length = kwargs.get('length', float())
        from geometry_msgs.msg import Point
        self.start_point = kwargs.get('start_point', Point())
        from geometry_msgs.msg import Point
        self.final_point = kwargs.get('final_point', Point())
        self.points = kwargs.get('points', [])

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
        if self.dir != other.dir:
            return False
        if self.child_id != other.child_id:
            return False
        if self.father_id != other.father_id:
            return False
        if self.l_lane_id != other.l_lane_id:
            return False
        if self.l_change_avbl != other.l_change_avbl:
            return False
        if self.r_lane_id != other.r_lane_id:
            return False
        if self.r_change_avbl != other.r_change_avbl:
            return False
        if self.behavior != other.behavior:
            return False
        if self.length != other.length:
            return False
        if self.start_point != other.start_point:
            return False
        if self.final_point != other.final_point:
            return False
        if self.points != other.points:
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
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'id' field must be an integer in [-2147483648, 2147483647]"
        self._id = value

    @builtins.property  # noqa: A003
    def dir(self):  # noqa: A003
        """Message field 'dir'."""
        return self._dir

    @dir.setter  # noqa: A003
    def dir(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dir' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'dir' field must be an integer in [-2147483648, 2147483647]"
        self._dir = value

    @builtins.property
    def child_id(self):
        """Message field 'child_id'."""
        return self._child_id

    @child_id.setter
    def child_id(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'child_id' array.array() must have the type code of 'i'"
            self._child_id = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'child_id' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._child_id = array.array('i', value)

    @builtins.property
    def father_id(self):
        """Message field 'father_id'."""
        return self._father_id

    @father_id.setter
    def father_id(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'father_id' array.array() must have the type code of 'i'"
            self._father_id = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'father_id' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._father_id = array.array('i', value)

    @builtins.property
    def l_lane_id(self):
        """Message field 'l_lane_id'."""
        return self._l_lane_id

    @l_lane_id.setter
    def l_lane_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'l_lane_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'l_lane_id' field must be an integer in [-2147483648, 2147483647]"
        self._l_lane_id = value

    @builtins.property
    def l_change_avbl(self):
        """Message field 'l_change_avbl'."""
        return self._l_change_avbl

    @l_change_avbl.setter
    def l_change_avbl(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'l_change_avbl' field must be of type 'bool'"
        self._l_change_avbl = value

    @builtins.property
    def r_lane_id(self):
        """Message field 'r_lane_id'."""
        return self._r_lane_id

    @r_lane_id.setter
    def r_lane_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'r_lane_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'r_lane_id' field must be an integer in [-2147483648, 2147483647]"
        self._r_lane_id = value

    @builtins.property
    def r_change_avbl(self):
        """Message field 'r_change_avbl'."""
        return self._r_change_avbl

    @r_change_avbl.setter
    def r_change_avbl(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'r_change_avbl' field must be of type 'bool'"
        self._r_change_avbl = value

    @builtins.property
    def behavior(self):
        """Message field 'behavior'."""
        return self._behavior

    @behavior.setter
    def behavior(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'behavior' field must be of type 'str'"
        self._behavior = value

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
    def start_point(self):
        """Message field 'start_point'."""
        return self._start_point

    @start_point.setter
    def start_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'start_point' field must be a sub message of type 'Point'"
        self._start_point = value

    @builtins.property
    def final_point(self):
        """Message field 'final_point'."""
        return self._final_point

    @final_point.setter
    def final_point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'final_point' field must be a sub message of type 'Point'"
        self._final_point = value

    @builtins.property
    def points(self):
        """Message field 'points'."""
        return self._points

    @points.setter
    def points(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'points' field must be a set or sequence and each value of type 'Point'"
        self._points = value
