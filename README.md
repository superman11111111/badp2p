# A bad peer-to-peer implementation in C

I am writing a simple C implementation of a peer-to-peer network for educational purposes. 

Read dis:
https://en.wikipedia.org/wiki/Peer-to-peer

## Architecture: 
* Nodes act simultaneously as "clients" and "servers"
* unstructured network

### Unstructured vs Structured
#### pros unstructured
* robust, harder to attack
* random connections allowed
* Every node is self sustained

#### cons unstructured
* Finding a particular piece of information gets exponentially harder with increasing number of nodes O(n^2)
* A lot of traffic
* Asymmetric information distribution 


