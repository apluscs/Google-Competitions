# Analysis

## Intuition
#### Observation 1
Order in which we visit rooms doesn't really matter. If placed in any cell in a given region, you are bound to visit some subarrays before others, no matter where you are placed.

An example doors array:
6 2 4 5 9

If you are placed in any room in the range of doors 2 - 4, you are bound to visit the middle three rooms before you visit the side doors. So if we were placed in room 3 (between the 2 and 4), the fourth room we would visit would be the same as the fourth room we would visit if we were placed in room 4. It would be room 5, because we visit rooms near 2 through 4 first before any others.

#### Observation 2
If you are given a start room and an end room, you can calculate how many rooms you would need to visit before visiting the end room. You must find the door with the maximum difficulty between the start and end. Consider it to be door x. Before visiting door x, we must visit all doors left of S with difficulty less than difficulty[x]. The range of doors left of S that we will visit will stop at y, where difficulty[y] > difficulty[x]. So in the end, we'll visit all rooms between y and F.

|---y-----S--x---F--|


## Strategy
For each query, binary search for the Kth room visited (F) given the start room by going through the range of doors left of S and the range of doors right of S. 
The farther F is from S in any direction, the number of rooms traveled to get to F only increases. That is because the distance from S to F will increase, and also the maximum difficulty between S and F will increase as well, forcing you to travel more left of S.

Now how should we obtain the maximum difficulty? Linear search & track? Too much time. Segment tree for range maximum query? Sure, in log(N) time. Sprase table? Easy to implement and O(1) time.

## Sparse Table
https://cp-algorithms.com/data_structures/sparse-table.html#:~:text=Sparse%20Table%20is%20a%20data,in%20O(1)%20time.

Basically, it's N * log2(N), so ST[i][j] = out of the 2^j values beyond and including i, what is the maximum? 
Building it is easy, where the first column is jus the given array, and for each later column, you just look at the two halves, whose maximums are in the previous column.
Getting the maximum between i and j is also easier. You just look at the first half and the second half and get the max of two maximums. If it's not a perfect power of 2, the two "halves" will overlaps.

```
1      2  3      5
|----------------|
|-half 1--|
       |-half 2--|
```
