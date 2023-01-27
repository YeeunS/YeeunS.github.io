---
layout: essay
type: essay
title: "Smart Questions with Brilliant Answers"
# All dates must be YYYY-MM-DD format!
date: 2023-01-26
published: true
labels:
  - smart questions
---

<img class="img-fluid" src="../img/smartquestions.jpeg">

## Introduction: Ask and Answer the Questions in a Smart Way

As a strong way of software engineering skills, communication is the most important aspect to handle technical issues. Now the use of open resources has been used widely, we can encounter numerous questions that require professional answers. And also we can realize that there are many people who want the answers without any steps, only focusing on the conclusion. This is not an appropriate approach when you face difficulties in the software development world. When you need help from technicians, it is essential to prepare how to ask questions before you get into the problem solving process. 

Before you ask, take your time and organize what you are having trouble with. This might take you to fix the problem by yourself, and help to direct other people with similar problems by connecting the search terms to what will be your problem and solution. When you ask, state exactly what your situation is. To be specific, vague and less information give the confusion to understand what the point is. It is better to specify the questions as much as possible. The thing you have to keep in mind is that it is also crucial not to ask different issues at the same time since this might distract the central point that you want to focus on. 

Not only is the smart question important, smart answers also give a way you can improve your software engineering skills. Depending on the questions, you can easily get the background information that you have to prepare for answering the questions. Proper answers should include relevant details, and also summarize enormous amounts of information to provide the answers in a smart way. 

Here are examples of smart question and not-smart question.

## Example1: A Smart Question

```
Suppose a1, b1, c1, and d1 point to heap memory, and my numerical code has the following core loop.

const int n = 100000;

for (int j = 0; j < n; j++) {
    a1[j] += b1[j];
    c1[j] += d1[j];
}
This loop is executed 10,000 times via another outer for loop. To speed it up, I changed the code to:

for (int j = 0; j < n; j++) {
    a1[j] += b1[j];
}

for (int j = 0; j < n; j++) {
    c1[j] += d1[j];
}

The question turned out to be of no relevance, as the behavior severely depends on the sizes of the arrays (n) and the CPU cache. 
So if there is further interest, I rephrase the question:

Could you provide some solid insight into the details that lead to the different cache behaviors 
as illustrated by the five regions on the following graph?

It might also be interesting to point out the differences between CPU/cache architectures, 
by providing a similar graph for these CPUs.

```
[Smart question from StackOverflow](https://stackoverflow.com/questions/8547778/why-are-elementwise-additions-much-faster-in-separate-loops-than-in-a-combined-l) 

Here you can see that the developer provides what she/he has a problem, and asks for solid insight into the details regarding the issues. And also, it clearly describes the sufficient information that helps to understand what the point of the problem is. Providing the full code (examples) helps to analyze the problem specifically, asking for a more technical method to solve the problem. With 2415 votes, we can see that this is a well-prepared and organized question that the author was provided with the precise solutions.

## Example2: A Not-Smart Question

```
Q: Calculate with java?

I don't know the right name in english when you want to calculate a number with a upper small number besides. 
Like 1,5 with a small 3 besides (the calculation of 1,5 * 1,5 * 1,5)

Is there a simple and uncomplicated way to do this in java? 
I want to calculate the volume. I hope you understand my question.

Thanks.
```
[Not-smart question from StackOverflow](https://stackoverflow.com/questions/7695763/calculate-with-java)

Here’s another example, but not in a smart way. As you can see in the title, the author throws the issue, but it is not clear. Also in explanation, even the author mentioned “I don’t know the right name in english…”, expecting the question to be entitled to an answer. As mentioned above, the smart question has to specify the issue’s background the developer is having as much in detail. 

## Thoughts

Many people may think that asking questions in a smart way is not necessary, especially in the online world. However, it has to be recognized that asking questions and answering them are the most important part for not only newbies in the software engineering field, but also for all people who are seeking to develop their technical skills. 
