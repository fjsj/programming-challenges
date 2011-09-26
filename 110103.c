/*
The Trip

A number of students are members of a club that travels annually to exotic locations. Their destinations in the past have included Indianapolis, Phoenix, Nashville, Philadelphia, San Jose, and Atlanta. This spring they are planning a trip to Eindhoven.
The group agrees in advance to share expenses equally, but it is not practical to have them share every expense as it occurs. So individuals in the group pay for particular things, like meals, hotels, taxi rides, plane tickets, etc. After the trip, each student's expenses are tallied and money is exchanged so that the net cost to each is the same, to within one cent. In the past, this money exchange has been tedious and time consuming. Your job is to compute, from a list of expenses, the minimum amount of money that must change hands in order to equalize (within a cent) all the students' costs.

The Input

Standard input will contain the information for several trips. The information for each trip consists of a line containing a positive integer, n, the number of students on the trip, followed by n lines of input, each containing the amount, in dollars and cents, spent by a student. There are no more than 1000 students and no student spent more than $10,000.00. A single line containing 0 follows the information for the last trip.

The Output

For each trip, output a line stating the total amount of money, in dollars and cents, that must be exchanged to equalize the students' costs.

Sample Input

3
10.00
20.00
30.00
4
15.00
15.01
3.00
3.01
0

Output for Sample Input

$10.00
$11.99
*/

#include <stdio.h>
#include <math.h>

int costs[1000];
int nCosts = 1000;

int sumCosts() {
    int sum = 0;
    
    int i = 0;
    for (i = 0; i < nCosts; i++) {
        sum += costs[i];
    }
    return sum;
}

int main() {
    for (;;) {
        scanf("%d", &nCosts);
        if (nCosts == 0) { 
            break;
        }
        
        int c = 0;
        for (c = 0; c < nCosts; c++) {
            int dollars;
            int cents;
            scanf("%d.%d", &dollars, &cents);
            costs[c] = dollars * 100 + cents;            
        }
        
        int sumCents = sumCosts();
        double avgCents = ((double) sumCents) / nCosts;
        double taken = 0;
        double given = 0;
        
        int i;
        for (i = 0; i < nCosts; i++) {
            double deltaCents = costs[i] - avgCents;
            if (deltaCents < 0) {
                taken += -((int) deltaCents) / 100.0;
            } else {
                given += ((int) deltaCents) / 100.0;
            }
        }
        
        printf("$%.2f\n", taken > given ? taken : given);
    }
    return 0;
}
