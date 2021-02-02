#include <memory>
#include <chrono>
#include <iostream>

#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

class ClockRecorder : public rclcpp::Node {
 public:
  ClockRecorder() : Node("clock_recorder") {
    auto use_sim_time = rclcpp::Parameter("use_sim_time", true);
    set_parameter(use_sim_time);
    auto timer_callback = [&]() {
                          auto now = this->now();
                          std::cout << static_cast<int>(now.seconds()) << std::endl;
    };
    timer_ = create_wall_timer(1s, timer_callback);
 };
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ClockRecorder>());
  rclcpp::shutdown();

  return 0;
}
