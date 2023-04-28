---
layout: essay
type: essay
title: "Designing Coding Castle"
# All dates must be YYYY-MM-DD format!
date: 2023-04-27
published: true
labels:
  - Reflection
  - Design Patterns
---

## Design castle

As a learner of programming, design pattern is another new scope to achieve our final project in ICS class. In software engineering, a design pattern isn't a finished design that can be transformed directly into code. Compared to a library or a framework, which can be inserted and used right away, I realized that the design pattern is more of a template to approach the problem at hand. It actually provides the information and solution that can be used in many different situations. While working on our project with my teammates, we basically used Meteor-Application-Template-React, modifying some codes to create our own data. We used different types of patterns in our final project, which organizes lots of codes and classes into larger structures so that all files can be maintained strongly. 

## MVC Design Pattern

The model-view-controller (MVC) design pattern is the earliest architectural pattern that is made up of three parts: model, view, and controller. In our case, the user interface conveyed by React is representing the view. MongoDB stands for the model that stores our data. And the controller is represented by the React Router that input is directed here first, processing the request through the model and passing it back to view.

## Singleton Pattern

Singleton is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.

Here’s an example of a singleton pattern from our project.


```javascript
import { Mongo } from 'meteor/mongo';
import SimpleSchema from 'simpl-schema';

class PeopleCollection {
  constructor() {
    this.name = 'PeopleCollection';
    this.collection = new Mongo.Collection(this.name);

    this.schema = new SimpleSchema({
      email: String,
      name: String,
      image: String,
      instrument: {
        type: String,
        allowedValues: ['Guitar', 'Bass', 'Drums', 'Vocals', 'Piano', 'Strings', 'Winds', 'Percussion', 'Brass', 'Other'],
        defaultValue: 'Other',
      },
      genre: {
        type: String,
        allowedValues: ['Rock', 'Jazz', 'EDM', 'Dubstep', 'Country', 'Pop', 'Classical', 'RhythmAndBlues'],
        defaultValue: 'Rock',
      },
      ...
```
Our project, Mele Manoa is a web application designed to bring musicians of UH together for jam sessions or performing bands. It is an easy way for them to find others with similar tastes and compatible musical abilities, by allowing students to create a profile indicating their musical tastes, their musical capabilities, and their musical goals.

## Continued

First thought of our project is that the theme seemed simple and straightforward to save our database. As the project is processed rapidly, we had to save lots of data in our collections so that it actually works as a web application. Still, it is challenging to finalize the project, but design patterns are powerful equipment for developers to understand how the different types of codes are bound together. It eventually helps me to get a better understanding of how common and useful they are.


