
#include "rclcpp/rclcpp.hpp"             
#include "std_msgs/msg/float32.hpp"     


class MySensor : public rclcpp::Node {
public:
  
  MySensor() : Node("sensor_node") {
    
    my_pub = this->create_publisher<std_msgs::msg::Float32>("distance", 10);

    
    my_timer = this->create_wall_timer(
        std::chrono::milliseconds(500), 
        std::bind(&MySensor::send_data, this)
    );
    
    dist = 5.0; 
  }

private:

  void send_data() {
    std_msgs::msg::Float32 message; 
    
    dist = dist - 0.1;              
    message.data = dist;            
    
    my_pub->publish(message);       
  }

  
  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr my_pub;
  rclcpp::TimerBase::SharedPtr my_timer;
  float dist;
};


int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);              
  auto my_node = std::make_shared<MySensor>(); 
  rclcpp::spin(my_node);                
  return 0;
}