# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Project goal

The project was about implementing and tuning a PID controller for steering a simulated car around a track. 


## Getting started

Please check the [project github link](https://github.com/udacity/CarND-PID-Control-Project) for all setup instructions.


## PID controller

### Implementation

The controller is fed with the cross track error (CTE), which is the derivation from the car to the lane center. Every PID controller consists of the following three components, which depend on error in different ways:

* P - proportional component:
	This component is proportional to the CTE - a large error leads to a large steering angle.
* I - Integral component:
	The integral component sums up the errors over time. A systematic error which leads to a deviation from the target value can thereby be corrected.
* D - Differential component:
	This component is proportional to the CTE difference. A large CTE change leads to a large dampening of the proportional controller.

All three components produce weighted control outputs based on their gain factors K_P, K_I and K_D which leads to the implemented PID formula:
steering_angle = - K_P * CTE - K_I * CTE_sum - K_D * CTE_diff


The following video shows the effect of a P controller, with K_I and K_D set to 0. The car starts driving straight, but gets off the track after a few seconds due to an increasingly oscillating path.

![P](./gifs/P_01.gif)


The oscillation can be controlled by adding a D component to the controller, which can be seen in the following clip.

![PD](./gifs/PD_01_07.gif)

The influence of the I controller could be shown in this case, since this component is supposed to correct a small error from the target value over a longer time. The fact that the track only has short straight sections and the car probably behaves in an ideal way makes it hard to show the positive influence of the I controller.


### Tuning

The controller was tuned manually since this seemed to be the fastest and most reasonable approach for this problem. 

1. P value:
	If this value is too small, the car cannot steer around tight curves, whereas if it is too large, the car gets off the track very fast. Therefor, the P value was increased until the car starts on a straight path and oscillates only after several seconds.
2. D value:
	This value was increased until the oscillations caused by the P controller were damped sufficiently so that the car followed a relatively straight and smooth path. A further increase of this value led to a less smooth solution due to a trembling steering angle.
3. I value:
	An increase of this value did not lead to noticeable improvements. Instead, the oscillations increased a bit on straight sections of the track, which is why a value of 0 was used.

The final parameters chosen were:
PID: (0.1, 0, 0.7)