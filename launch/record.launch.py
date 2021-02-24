from launch import LaunchDescription
from launch_ros.actions import Node
from tracetools_launch.action import Trace

def generate_launch_description():
    return LaunchDescription([
        Trace(
            session_name='clock_recorder',
            events_kernel=[],
			events_ust=['rostime:ros_time']
        ),
        Node(
            package='clock_recorder',
            executable='recorder'
        )
    ])
