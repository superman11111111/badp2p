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

I got sidetracked, now want to understand how sys/socket.h socket sends data. what syscalls? 

what is INDIRECT_CALL_INET ?? in line 651 in https://github.com/torvalds/linux/blob/master/net/socket.c ??

HOW DOES IT ALL WORK I DONT SEE THE ASSEMBLY 

pls explain linus


