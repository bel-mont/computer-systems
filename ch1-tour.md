# Computer Systems - Tour of computer systems
## Amdahl's Law
Execution time of the enhanced system is given by:
Tn = (1 - a)To + (aTo)/k

Simplified to:
Tn = To((1 - a) + a/k)

Where:
To = Execution time of the original system
Tn = Execution time of the enhanced system
a = Fraction of the execution time (To) that can be improved
k = Speedup factor of the enhanced system

(1 - a)To is the fraction of the original system that cannot be improved
(aTo)/k is the fraction of the original system that can be improved

Which makes the formula mean that the execution time of the enhanced system is the sum
of the time that cannot be improved and the time that can be improved.

### Speedup computation
S = 1 / ((1 - a) + a/k)

### Determining a and k
To determine a and k, we can use the following formulas:
a = original time spent on the part that can be improved / total original time
k = original time for the part / improved time for the part

### Example
As an example, consider the case where a part of the system that initially
consumed 60% of the time (α = 0.6) is sped up by a factor of 3 (k = 3). Then
we get a speedup of 1/[0.4 + 0.6/3] = 1.67×.

Using the variables above in our formula, we get:
Tn = To((1 - 0.6) + 0.6/3) 
   = To(0.4 + 0.2) 
   = To(0.6)

Assuming our current execution time is 2.5 seconds:
Tn = 2.5 * 0.6
   = 1.5 seconds

The speedup is then:
S = 1 / ((1 - 0.6) + 0.6/3)
  = 1 / (0.4 + 0.6/3)
  = 1 / 0.6
  = 1.67

## Calculating the required increase from a given speedup
Reversing the formula:
S = 1 / ((1 - a) + a/k)
S((1 - a) + a/k) = 1
(1 - a) + a/k = 1/S
a / k = 1/S - (1 - a)
k = a / (1 / S - (1 - a))

# Exercises
## Problem 1.1
Speedup for the tree is S = 1.25

To reach this value we follow the formula:
total distance = 2500
speed = 100 km/hr
total hours = 25

New speed is given as: 1500 km can now be done at 150 km/hr

Given these values, we can calculate the required data for the formula:
speed = 2500/100 = 25
speedupDistance = 15/25 = .6
a = .6 // .6 of the time will be improved
k = (15 / 10) = 1.5 // the .6 equals to 15 hours, that will now take 10 hours

Which gives the resulting formula of:
Tn = 25((1 - .6) + .6/1.5)
Tn = 25(.4 + .4)
Tn = 25(.8)
Tn = 20

With a speedup of:
S = 1 / ((1 - .6) + .6/1.5)
S = 1 / (.4 + .4)
S = 1 / .8
S = 1.25

**This can be simplified to:**
`25 / (10 + 10)`

Where `25` is the total initial time,

`10` is the time that cannot be improved,

and `10` is the new time for the improved part.

## Problem 1.2
To get the required speed to get a speedup of 1.67, we have to reverse the formula to find k,
from which we can then find the new km/h we need.

Total Distance (D): 2,500 km
Original Speed (V₁): 100 km/hr
Distance To Improve (D_improve): 1,500 km
Unimproved Distance (D_unimproved): 1,000 km
Desired Speedup (S): 1.67

Calculate Desired Total Time (T₂)
`T₂ = T₁/S = 25 hours / 1.67 = 14.9701`

Calculate New Time for Improved Section
`Timproved_new = T₂−Tunimproved = 14.9701 hours −10 hours = 4.9701 hours`

Calculate Original Time for Section to Improve
`Timproved_original = D_improve/V₁ = 1,500 km / 100 km/hr = 15 hours`

Calculate Required Speedup Factor (k) for Improved Section
`k = Timproved_original / Timproved_new = 15hours / 4.9701hours  = 3.0179`

Calculate New Speed for Improved Section
`Vimproved = k * V1 = 3.0179 * 100km/hr  = 301.79km/hr`

**Alternatively, directly calculate Vimproved:**
`Vimproved = D_improve / Timproved_new = 1,500 km / 4.9701 hours = 301.79 km/hr`