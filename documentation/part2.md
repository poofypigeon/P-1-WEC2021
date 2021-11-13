# Programming Submission for Part 2 - WEC'21
    > Paige Liebster, Aiden Fox-Ivey, Nicole Nassar

# Alternative Entry Method
In the case of a broken key, each key has the ability to overflow into the values held by the next key:
```
[0](_)    -> [2](abc)
[2](abc)  -> [3](def)
[3](def)  -> [4](ghi)
[4](ghi)  -> [5](jkl)
[5](jkl)  -> [6](mno)
[6](mno)  -> [7](pqrs)
[7](pqrs) -> [8](tuv)
[8](tuv)  -> [9](wxyz)
[9](wxyz) -> [0](_)
```
For example, in order to type a 'd' in the case that key 3 is broken, the user would press key 3 four times.
Or, in order to type an 'a' in the case that key 2 is broken, the user would press key 0 two times.

The time that is taken when compensating for a broken button can be calculated easily by adding a fixed time increment to the letters on the broken button. The time increment is dependant on how many letter the previous character represents: key 2 adds +0.25s for one character in key 0; keys 0 and 8 add +1.0s for four characters in keys 9 and 7 respectively; all other keys add +0.75s for 3 characters in the previous keys.