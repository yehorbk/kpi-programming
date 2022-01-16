# Pyramids
Determining the sequence of medians for a given input array.

## Variant of task
In this work you need to solve the next task: determining the sequence of 
medians for a given input array. Recall that the median for an array is
element that situated in the center in sorted array. If count of elements is odd
the median and it index is determined like [n / 2] (n - count of elements of 
input array). If count of elements is even, then it will be two medians and two
indexes and it determined like [n / 2] and [n / 2] + 1. Task is formulated as 
follows: We have the input array A = [x1, ..., xN] is given.
Suppose that the elements of an array arrive at the input of the program 
sequentially: at each moment in time a new element xi is considered. It is 
necessary for each i (from 1 to N) to determine the median of the subarray 
A '= [x1, ..., xi], that is, the median for the array of elements received by 
the program at this point in time. It is necessary to solve this problem using 
the structure of the pyramid data and in such a way that each median is 
determined by the time O (log (i)).
