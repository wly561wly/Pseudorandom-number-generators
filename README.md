# Pseudorandom-number-generators
a report about Pseudorandom number generators

### Introduction

Random numbers play a significant role in daily life and scientific research. They are crucial in various fields such as cryptography, game development, and data analysis. Although we often require random numbers, what we typically generate are pseudo-random numbers. These numbers may appear random at first glance, but they are actually determined by algorithms, thus possessing certain patterns and potentially being decipherable in theory. 

In computer science, the use of pseudo-random number generators (PRNGs) to produce sequences of random numbers is an essential step in the performing various tasks. However, because modern computers are primarily designed based on the von Neumann architecture, these computers are incapable of generating truly random numbers. This is because they can only execute tasks in an orderly manner according to predefined program instructions.

The main content of this paper is to introduce the principles of various pseudorandom and true random number generators, discuss the implementation methods of random number APIs in multiple programming languages, and design relevant experiments to verify the NIST tests.

### Basic Concept

According to the principles of cryptography\footnote{For more information, refer to \url{https://zh.wikipedia.org/wiki/密碼學}.}, the randomness of random numbers can be tested by three standards:
- Statistical pseudo-randomness. This refers to the condition where in a given sample of random bit streams, the number of 1s is roughly equal to the number of 0s. Similarly, the quantities of '10', '01', '00' and '11' are approximately equal. Similar criteria are known as statistical randomness. Numbers that meet such requirements appear random to the human eye at first glance.
- Cryptographic pseudo-randomness. It is defined as the inability to effectively deduce the remaining part of a random sample given a part of the random sample and the random algorithm.
-True randomness. It is defined as the irreproducibility of a random sample. In reality, true random numbers do not exist as long as boundary conditions are given. However, if the boundary conditions for generating a true random number sample are very complex and difficult to capture (such as local background radiation fluctuation values), it can be considered that true random numbers are generated using this method. But in fact, this is only a pseudo-random number very close to true random numbers. Generally, background radiation, physical noise, coin tossing, etc. are believed to be observable and understandable. Any random numbers generated based on classical mechanics are just pseudo-random numbers.

Correspondingly, random numbers are divided into three categories:

- $\textbf{Weak Pseudo-random numbers}$: Random numbers that meet the first condition.
- $\textbf{Cryptographically secure pseudo-random numbers}$: Random numbers that meet the first two conditions. They can be calculated through a cryptographically secure pseudo-random number generator. 
- $\textbf{True random numbers}$: Random numbers that meet all three conditions.

Random numbers are very important in cryptography. The generation of session keys, which are widely used in confidential communications, requires the participation of true random numbers. If a random number generation algorithm is flawed, the session key can be directly deduced. If such an accident occurs, any encryption algorithm will lose its meaning.
