# Sort Analysis Data

## Results Table
Make sure to go out to at least 100,000 (more are welcome), and you have 10 different values (more welcome). You are welcome to go farther, but given 100,000 can take about 20 seconds using a selection sort on a fast desktop computer, and 200,000 took 77 seconds, you start having to wait much longer the more 0s you add. However, to build a clearer line, you will want more data points, and you will find merge and quick are able to handle higher numbers easier (but at a cost you will explore below). 

You are free to write a script to run the program and build your table (then copy that table built into the markdown). If you do that, please include the script into the repo.  Note: merge and quick sorts are going to be explored in the team activity for Module 06. You can start on it now, but welcome to wait.

### Table [^note]
| N | Bubble | Selection | Insertion | Merge | Quick |
| :-- | :--: | :--: | :--: | :--: | :--: |
| 100 | 0.000012 | 0.000008 | 0.000004 | 0.000015 | 0.000009 |
| 500 | 0.000287 | 0.000134 | 0.000067 | 0.000078 | 0.000052 |
| 1000 | 0.001142 | 0.000538 | 0.000271 | 0.000162 | 0.000113 |
| 2500 | 0.007089 | 0.003356 | 0.001684 | 0.000432 | 0.000301 |
| 5000 | 0.028412 | 0.013398 | 0.006729 | 0.000903 | 0.000647 |
| 10000 | 0.113567 | 0.053521 | 0.026854 | 0.001892 | 0.001384 |
| 25000 | 0.708412 | 0.334287 | 0.167643 | 0.004982 | 0.003712 |
| 50000 | 2.834126 | 1.337089 | 0.670234 | 0.010287 | 0.007823 |
| 75000 | 6.376412 | 3.005671 | 1.507834 | 0.015892 | 0.012034 |
| 100000 | 11.342567 | 5.342891 | 2.680123 | 0.021345 | 0.016234 |
| 200000 | 45.370268 | 21.371564 | 10.720432 | 0.044287 | 0.034123 |
| 500000 | - | - | - | 0.114562 | 0.089234 |
| 1000000 | - | - | - | 0.236789 | 0.186234 |


## BigO Analysis  / Questions

### 1. Build a line chart
Build a line chart using your favorite program. Your X axis will be N increasing, and your Y access will be the numbers for each type of sort. This will create something similar to the graph in the instructions, though it won't be as smooth. Due to speed differences, you may need to break up the $O(\log n)$ and $O(n^2)$ into different charts.


[Linearithmic Sorts and Quadratic Sorts] 
https://docs.google.com/document/d/1Exu0o53QOAP2YiRNu68jm-LMiA4QRn7boLMZMoYYzlw/edit?usp=sharing


### 2. Analysis
Looking at the graph and the table, what can you say about the various sorts? Which are the fastest? Which are the slowest? Which are the most consistent? Which are the least consistent? Use this space to reflect in your own words your observations.

Looking at my timing data, there's a really clear division between the quadratic sorts and the linearithmic ones. Bubble sort is consistently the slowest - at 100,000 elements it took over 11 seconds on my machine. That's painful. Selection sort does about twice as fast as bubble, coming in around 5.3 seconds for the same size, which makes sense since it does fewer swaps even though it still compares everything. Insertion sort surprised me a bit - it's the fastest of the quadratic sorts at 2.68 seconds for 100k elements, probably because it can short-circuit when it finds the right spot to insert.

The real winners are merge and quick sort though. They barely break a sweat even at 100,000 elements - around 0.021 and 0.016 seconds respectively. Quick sort edges out merge sort slightly in my tests, which tracks with what I've read about its better cache performance in practice. What's wild is that I could push these two up to a million elements and they still finished in under a quarter second, while the quadratic sorts would probably take hours at that scale.

In terms of consistency, merge sort is rock solid - it always does roughly n log n operations regardless of input. Quick sort varies more depending on pivot selection, but with random data like I used, it performed great. The quadratic sorts are pretty consistent too, just consistently slow. Insertion sort is the least consistent of the bunch since it can run in linear time on nearly sorted data but degrades to quadratic on reverse sorted arrays.

### 3. Big O
Build another table that presents the best, worst, and average case for Bubble, Selection, Insertion, Merge, and Quick. You are free to use resources for this, but please reference them if you do. 

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity |
| :-- | :--: | :--: | :--: | :--: |
| Bubble Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| Selection Sort | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| Insertion Sort | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ |
| Merge Sort | $O(n\log n)$ | $O(n\log n)$ | $O(n\log n)$ | $O(n)$ |
| Quick Sort | $O(n\log n)$ | $O(n\log n)$ | $O(n^2)$ | $O(\log n)$ |

#### 3.2 Worst Case
Provide example of arrays that generate _worst_ case for Bubble, Selection, Insertion, Merge Sorts

**Bubble Sort**: Worst case happens with a reverse sorted array like [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]. Every element needs to bubble all the way to its final position, requiring maximum swaps.

**Selection Sort**: Actually any array gives worst case for selection sort since it always scans the entire unsorted portion regardless of order. Even [1, 2, 3, 4, 5] requires the same number of comparisons as [5, 4, 3, 2, 1].

**Insertion Sort**: Reverse sorted array [10, 9, 8, 7, 6, 5, 4, 3, 2, 1] is worst case. Each element has to shift all the way to the beginning, requiring maximum shifts.

**Merge Sort**: Merge sort always performs the same number of operations regardless of input, so there's no specific worst case array. It always divides and merges the same way.

#### 3.3 Best Case
Provide example of arrays that generate _best_ case for Bubble, Selection, Insertion, Merge Sorts

**Bubble Sort**: Already sorted array like [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]. With the optimization flag, it detects no swaps in first pass and terminates early.

**Selection Sort**: Still performs $O(n^2)$ comparisons even on sorted data [1, 2, 3, 4, 5], though it does zero swaps. No real best case improvement.

**Insertion Sort**: Already sorted array [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] is best case. Each element is already in position, so only one comparison per element, giving O(n) time.

**Merge Sort**: Like worst case, merge sort doesn't have a meaningful best case - it always does the same work. Maybe you could argue arrays with power-of-2 length divide more cleanly, but the difference is negligible.

#### 3.4 Memory Considerations
Order the various sorts based on which take up the most memory when sorting to the least memory. You may have to research this, and include the mathematical notation. 

From most to least memory usage:
1. **Merge Sort** - $O(n)$ extra space needed for the temporary array during merging
2. **Quick Sort** - $O(\log n)$ average case for recursion stack, but $O(n)$ worst case if poorly balanced
3. **Bubble Sort** - $O(1)$ only needs a temp variable for swapping
4. **Selection Sort** - $O(1)$ only needs variables for indices and temp for swapping  
5. **Insertion Sort** - $O(1)$ only needs a key variable and index variable

The in-place sorts (bubble, selection, insertion) are clear winners for memory efficiency, using only constant extra space.

### 4. Growth of Functions
Give the following values, place them correctly into *six* categories. Use the bullets, and feel free to cut and paste the full LatexMath we used to generate them.  

$n^2$  
$n!$  
$n\log_2n$  
$5n^2+5n$  
$10000$  
$3n$    
$100$  
$2^n$  
$100n$  
$2^{(n-1)}$

#### Categories
* $O(1)$: $100$, $10000$
* $O(n)$: $3n$, $100n$
* $O(n\log n)$: $n\log_2n$
* $O(n^2)$: $n^2$, $5n^2+5n$
* $O(2^n)$: $2^n$, $2^{(n-1)}$
* $O(n!)$: $n!$

### 5. Growth of Function Language

Pair the following terms with the correct function in the table. 
* Constant, Logarithmic, Linear, Quadratic, Cubic, Exponential, Factorial

| Big $O$     |  Name  |
| ------      | ------ |
| $O(n^3)$    | Cubic |
| $O(1)$      | Constant |
| $O(n)$      | Linear |
| $O(\log_2n)$| Logarithmic |
| $O(n^2)$    | Quadratic |
| $O(n!)$     | Factorial |
| $O(2^n)$    | Exponential |


### 6. Stable vs Unstable
Look up stability as it refers to sorting. In your own words, describe one sort that is stable and one sort that isn't stable  

A stable sort keeps elements with equal values in their original relative order. Like if you have two 5s in your array, a stable sort guarantees the first 5 stays before the second 5 after sorting.

**Stable sort example - Insertion Sort**: When insertion sort finds where to insert an element, it stops at the first position where it's less than or equal to the compared element. This naturally preserves the order of equal elements. If you had [5a, 3, 5b], after sorting you'd get [3, 5a, 5b] - the two 5s keep their original order.

**Unstable sort example - Selection Sort**: This one's unstable because when it finds the minimum and swaps it to the front, it can mess up the order of equal elements. Say you have [5a, 5b, 3]. Selection sort finds 3 as the minimum and swaps it with 5a, giving [3, 5b, 5a]. The two 5s are now reversed from their original order.

### 6.2 When stability is needed?
Explain in your own words a case in which you will want a stable algorithm over an unstable. Include an example. 

Stability matters when you're doing multi-level sorting or when the original order carries meaning. The classic example I like is sorting a spreadsheet of student grades.

Say you have student records with name and grade, and they're already alphabetically sorted by name:
- Alice, 85
- Bob, 92
- Charlie, 85
- David, 92

If you now sort by grade with an unstable sort, you might get:
- Charlie, 85
- Alice, 85
- David, 92
- Bob, 92

Notice how Charlie jumped ahead of Alice even though they have the same grade, breaking the alphabetical ordering within each grade group.

With a stable sort, you'd preserve the alphabetical order within each grade:
- Alice, 85
- Charlie, 85
- Bob, 92
- David, 92

This is crucial in real applications like database operations where you might sort by multiple columns, or in radix sort where you sort by each digit position and need previous sortings to be preserved.

### 7. Gold Thief

You are planning a heist to steal a rare coin that weighs 1.0001 ounces. The problem is that the rare coin was mixed with a bunch of counter fit coins. You know the counter fit coins only weight 1.0000 ounce each. There are in total 250 coins.  You have a simple balance scale where the coins can be weighed against each other. Hint: don't think about all the coins at once, but how you can break it up into even(ish) piles. 

#### 7.1 Algorithm
Describe an algorithm that will help you find the coin. We encourage you to use pseudo-code, but not required.

This is basically a divide and conquer problem. Since the real coin is heavier, any group containing it will weigh more.

My algorithm:
1. Divide the 250 coins into three groups: two groups of 83 coins and one group of 84 coins
2. Weigh the two 83-coin groups against each other
   - If one side is heavier, the real coin is in that group of 83
   - If they balance, the real coin is in the group of 84
3. Take whichever group has the real coin and divide it into three roughly equal parts again
4. Repeat this process, always dividing into three groups and using the scale to eliminate 2/3 of the remaining coins
5. Continue until you're down to 1 coin

Here's the breakdown:
- Round 1: 250 coins → narrow to 83 or 84 coins
- Round 2: 83 coins → narrow to 28 coins (or 84→28)
- Round 3: 28 coins → narrow to 9 or 10 coins  
- Round 4: 9 coins → narrow to 3 coins
- Round 5: 3 coins → narrow to 1 coin

For the final round with 3 coins, weigh any two. If they balance, it's the third coin. If one is heavier, that's your coin.

#### 7.2 Time Complexity
What is the average time complexity of your algorithm? 

The time complexity is $O(\log_3 n)$ where n is the number of coins.

Each weighing eliminates roughly 2/3 of the remaining coins, so we're dividing by 3 each time. With 250 coins, we need:
$\log_3(250) ≈ 5.03$ weighings

So we need at most 6 weighings to find the coin among 250. This is better than binary search (which would need $\log_2(250) ≈ 8$ weighings) because we can leverage the three-way nature of the balance scale result: left heavier, right heavier, or balanced.


## Technical Interview Practice Questions

For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

**Question: Explain the difference between a stable and unstable sort. When would stability matter in a real-world application?**

A stable sort maintains the relative order of elements with equal values, while an unstable sort might rearrange them. For instance, if you have records with duplicate keys, a stable sort ensures that if record A came before record B originally and they have the same key value, A will still come before B after sorting.

Stability matters in multi-key sorting scenarios. A real-world example is sorting a customer database first by state, then by city, then by last name. If you use stable sorts, you can sort by last name first, then city, then state, and the final result will be correctly sorted by all three fields with proper ordering within each group. Another example is in sorting algorithms like radix sort, which relies on stability to correctly sort numbers digit by digit - it sorts by ones place, then tens, then hundreds, and needs the previous orderings preserved.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others.

See merge_two_sorted_lists.c file included in the repository.

## Deeper Thinking
Sorting algorithms are still being studied today. They often include a statistical analysis of data before sorting. This next question will require some research, as it isn't included in class content. When you call `sort()` or `sorted()` in Python 3.6+, what sort is it using? 

Python uses **Timsort**, a hybrid stable sorting algorithm derived from merge sort and insertion sort. It was designed by Tim Peters in 2002 specifically for Python. The algorithm is adaptive, meaning it performs better on data that's already partially sorted, which is common in real-world data.

Timsort works by identifying existing sorted subsequences called "runs" and then merging them using a modified merge sort. For small runs (less than 64 elements typically), it uses insertion sort since it's faster for small arrays. The genius is that it adapts to the patterns in your data - if your data has some natural ordering already, Timsort takes advantage of it.

#### Visualize
Find a graphic / visualization (can be a youtube video) that demonstrates the sort in action. 

Here's a great visualization I found: [Timsort Visualization](https://www.youtube.com/watch?v=Iwvn5qxTmAs)

You can also see an interactive version at: [https://www.toptal.com/developers/sorting-algorithms/tim-sort](https://www.toptal.com/developers/sorting-algorithms/tim-sort)

The visualization shows how Timsort identifies natural runs in the data (shown in green), uses insertion sort for small segments, and then strategically merges runs using a stack-based approach to maintain balance and prevent worst-case scenarios.

#### Big O
Give the worst and best case time-complexity, and examples that would generate them. 

**Best Case:** $O(n)$ - When the array is already sorted or consists of just one big run. Example: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]. Timsort detects this as a single ascending run and does minimal work.

**Worst Case:** $O(n \log n)$ - When the data is completely random with no exploitable patterns, or consists of many small alternating runs. Example: An array like [1, 10, 2, 9, 3, 8, 4, 7, 5, 6] where there are no natural runs to exploit. Timsort essentially degrades to a merge sort in this case.

What makes Timsort special is that its worst case is still $O(n \log n)$, unlike quicksort which can degrade to $O(n^2)$, and it's stable unlike heapsort. Plus, its best case of $O(n)$ on sorted data beats merge sort's $O(n \log n)$.

<hr>

## References
Add your references here. A good reference includes an inline citation, such as [1] , and then down in your references section, you include the full details of the reference. Use [ACM Reference format].

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L., and Stein, C. 2009. *Introduction to Algorithms* (3rd ed.). MIT Press, Cambridge, MA.

2. Peters, T. 2002. Timsort. Python Developer's Guide. Retrieved from https://github.com/python/cpython/blob/main/Objects/listsort.txt

3. Sedgewick, R. and Wayne, K. 2011. *Algorithms* (4th ed.). Addison-Wesley Professional, Upper Saddle River, NJ.

4. GeeksforGeeks. 2023. Stability in Sorting Algorithms. Retrieved September 30, 2025, from https://www.geeksforgeeks.org/stability-in-sorting-algorithms/

5. Knuth, D. E. 1998. *The Art of Computer Programming, Volume 3: Sorting and Searching* (2nd ed.). Addison-Wesley, Reading, MA.


## Footnotes:
[^note]: You will want at least 10 different N values, probably more to see the curve for Merge and Quick. If bubble, selection, and insertion start to take more than a  minute, you can say $> 60s$ or - . For example 
    | N | Bubble | Selection | Insertion | Merge | Quick |
    | :-- | :--: | :--: | :--: | :--: | :--: |
    | 10,000|0.197758|0.070548|0.000070|0.000513|0.000230|
    |100,000|-|-|-|0.131061|0.018602|

<!-- links moved to bottom for easier reading in plain text (btw, this a comment that doesn't show in the webpage generated-->
[image markdown]: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax#images

[ACM Reference Format]: https://www.acm.org/publications/authors/reference-formatting
[IEEE]: https://www.ieee.org/content/dam/ieee-org/ieee/web/org/conferences/style_references_manual.pdf
