/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].*/




int minCostClimbingStairs(vector<int>& cost) {
        vector<int> min_cost(cost.size()+1,0);
        for(int i=2;i<min_cost.size();i++)
        {
            min_cost[i]=min(cost[i-1]+min_cost[i-1],cost[i-2]+min_cost[i-2]);
        }
        int n= min_cost.size();
        return min_cost[n-1];
    }
    
 /*Algorithm

With our base cases and recurrence relation, we can now easily solve this problem.

    Define an array minimumCost, where minimumCost[i] represents the minimum cost of reaching the ithi^{th}ith step. The array should be one element longer than costs and start with all elements set to 0.
        The reason the array should contain one additional element is because we will treat the top floor as the step to reach.

    Iterate over the array starting at the 2nd index. The problem statement says we are allowed to start at the 0th0^{th}0th or 1st1^{st}1st step, so we know the minimum cost to reach those steps is 0.

    For each step, apply the recurrence relation - minimumCost[i] = min(minimumCost[i - 1] + cost[i - 1], minimumCost[i - 2] + cost[i - 2]). As you can see, as we populate minimumCost, it becomes possible to solve future subproblems. For example, before solving the 5th and 6th steps we are required to solve the 4th step.

    At the end, return the final element of minimumCost. Remember, we are treating this "step" as the top floor that we need to reach.
*/
