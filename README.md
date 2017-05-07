# CarND-Controls-PID

My submission to the PID Controller Project for Udacity's Self-Driving Car Engineer nanodegree, second term.

---

## Implementation Notes

The Proportional–Integral–Derivative (PID) controller is _"a control loop feedback mechanism_ [that] _continuously calculates an error value_ `e(t)` _as the difference between a desired setpoint and a measured process variable and applies a correction based on proportional, integral, and derivative terms (sometimes denoted P, I, and D respectively)._ [*](https://en.wikipedia.org/wiki/PID_controller)

In the context of the assignment, the different PID terms collaborate to produce adequate steering corrections based on the current cross-track error (i.e. the distance from the center of the lane):

* The proportional term produces a baseline immediate correction in the direction opposite to the error. This is most important where there is a sudden departure from the center of the track, e.g. when the car approaches a turn in the road;
* The differential term provides a smoothing factor to the correction, preventing the car from settling in an oscillating path around the track center;
* Finally, the integral term enables the controller to overcome systemic bias, and provides an extra pull when the car is under a sustained push away from the track center (e.g. during a prolonged turn).

In practice, there is a tension between responsivity and smooth driving when setting PID parameters: the adjustments that enable more prompt route corrections are the same that cause the car to wobble around the track center. With this in mind, starting from defaults `(Kp = 1, Kd = 0, Ki = 0)`, parameters were adjusted empirically by following the rules below:

* The proportional coefficient `Kp` was reduced until the controller's response remained within the range `[-1, 1]`;
* The differential coefficient `Kd` was increased until the steering responses achieved a reasonable level of smoothness;
* The integral coefficient `Ki` was increased until the car would pull back against centrifugal forces with enough strength to remain on the road.

Of the three parameters, the one that required most care during experiments was the integral coefficient `Ki`. Because it controls the response to errors accumulated over time, relatively small changes could have a dramatic effect in the car's behavior. In the end, the set `(Kp = 0.1, Kd = 2, Ki = 0.004)` was found to be a reasonable compromise between responsivity and smoothness.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.
