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