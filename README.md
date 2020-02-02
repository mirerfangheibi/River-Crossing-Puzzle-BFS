# River Crossing Puzzle Solving Using Breadth-First Search

River Crossing puzzle <sup>1</sup> is one of constraint satisfaction problems. There are some varieties of it, for instance, fox, goose, and bag of beans puzzle. The whole idea is that there is a river, a boat with limited capacity, some opposing entities that shouldn't be left together alone. The version that this program is coined to solve is the following. There are the policemen and the thief. There is a father that he has no problem with his two sons, but he wants to kill her wife's two daughters. Also, there is a mother that wants to kill the aforementioned sons of the father. The mother and the father love each other and don't want to show their hatred of the siblings. Furthermore, the thief should be either alone on one side or cuffed beside the policemen.

# Model and Solution

For solving the problem using the BFS<sup>2</sup> algorithm, the problem model and states should be defined. States are boolean arrays with nine elements, including the boat. False means initial riverside and true corresponds to the other side of the river. Hence, the main operation for generating sibling states from each state is toggling; Starting from the initial state (a false boolean array), in each iteration, one or two of the people and the boat are being toggled.


# Screenshot
![enter image description here](https://raw.githubusercontent.com/mirerfangheibi/River-Crossing-Puzzle-BFS/master/ScreenShot.png)

# Further Reading
[1] [River crossing puzzle - Wikipedia](https://en.wikipedia.org/wiki/River_crossing_puzzle) 

[2] [Breadth-First Search - Wikipedia](https://en.wikipedia.org/wiki/Breadth-first_search)
