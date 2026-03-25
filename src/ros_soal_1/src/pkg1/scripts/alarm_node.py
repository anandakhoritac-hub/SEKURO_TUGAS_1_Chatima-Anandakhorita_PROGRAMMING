#!/usr/bin/env python3

import rclpy                  #
from rclpy.node import Node    
from std_msgs.msg import Float32 


class MyAlarm(Node):
    def __init__(self):
      
        super().__init__('alarm_node') 

        
        self.my_sub = self.create_subscription(
            Float32, 
            'distance', 
            self.check_dist, 
            10)

    
    def check_dist(self, msg):
        current_distance = msg.data 
        
        if current_distance < 0.5:
            self.get_logger().warn(f"!!! STOP !!! Object is only {current_distance:.2f}m away!")
        else:
            self.get_logger().info(f"Distance is safe: {current_distance:.2f}m")


def main():
    rclpy.init()            
    my_node = MyAlarm()      
    rclpy.spin(my_node)     
    rclpy.shutdown()        

if __name__ == '__main__':
    main()