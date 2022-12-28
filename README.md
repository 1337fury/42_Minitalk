## 42 Minitalk
<img width="100px" alt="LIBBFT" src="https://user-images.githubusercontent.com/107589431/209883952-29ca7aeb-1ca5-46ed-9d63-90cbaf45aa87.png">
The 42 `minitalk` project is a networking project in which you are required to create a communication system between two programs using only the signals SIGUSR1 and SIGUSR2.

In the `minitalk` project, one program (the sender) sends messages to another program (the receiver) by sending a series of SIGUSR1 and SIGUSR2 signals. The receiver receives these signals and interprets them as binary digits (0 or 1). By combining these binary digits into a series of bytes, the receiver is able to reconstruct the original message sent by the sender.

To complete the `minitalk` project, you will need to implement the sender and receiver programs in C. You will also need to write appropriate unit tests to ensure that your implementations are correct.

Some of the key challenges of the `minitalk` project include:

- `Ensuring` that the sender and receiver programs are able to communicate reliably and efficiently, despite the limitations of the signaling system
- `Handling` signals in a concurrent environment, as the sender and receiver programs will be running at the same time
- `Debugging` the programs when things go wrong, as it can be difficult to track down problems in a system that relies on signals
Overall, the 42 minitalk project is a great opportunity to learn about networking and concurrent programming in C. It is also a good opportunity to practice your debugging skills, as you will likely encounter a number of challenges along the way.
