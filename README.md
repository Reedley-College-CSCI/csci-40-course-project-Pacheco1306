[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Ay551EX-)
# CS1 Final Project - [Project Title]

## 1. Overview
- What problem does your project solve?  
- Briefly describe the purpose and key features of your program.  

---    My project solves the problem of helping a user keep track of the food they have eaten during the day. The program records food names, calories, fat, and carbohydrates, then compares the total calories eaten to the user's daily calorie goal. The prupose of the program is to make a simple calorie tracker that stores food data, displays food entries, calculate nutrion totals, and saves the data between program runs. Key features include reading from a file, adding new food items, viewing all recorded foods, displaying  a nutrion summary, and saving the updated food list. 

## 2. Design Decisions
- What fundamental programming constructs and data types did you use, and why?  
- Why did you choose to structure your data using structs?  
- How did you implement searching and sorting? What algorithms did you use and why?  
- How do you ensure data persistence between program runs?  
- Did you consider alternative approaches? If so, why did you not use them?  

--- I used variables, loops, conditions, functions, arrays, pointers, structs, and file input/output. I used loops so the menu can continue running until the user chooses to exit. I used conditionals to check menu choices, invlaid input, and whether the user went over or under their calorie goal for the day. 
    I chose structs because each food item has multiple related pieces of data. Name, calories, fat, and carbohydrates. Storing these fields in "FoodItem" struct keeps the program organized instead of using seperate arrays for each value. 
Data persistence is handled by reading food items from calories.txt when the program starts and saving the updated food list back to the file when the user exits. This allows teh food data to remain available between program runs. 

## 3. Testing Summary
- **Structured Testing Log:** Include a table with test cases, expected output, actual output, and pass/fail status.  
- What testing methods did you use?  
- Provide examples of test inputs (valid and invalid) and describe how your program responds.  

---

## 4. Technical Walkthrough
- Explain the main functionality of your program.  
- **Include a link to your required video demonstration** showcasing how the project works (**3-7 minutes**). 
    Make sure it shareable without approval needed.

--- https://youtu.be/385mrYsRQ4w

## 5. Challenges and Lessons Learned
- What challenges did you encounter while working on this project?  
- What key lessons did you learn about programming and problem-solving?  

--- A challenge I faced during this project was mostly when working with pointers and dynamic memory allocation. It was difficult to solidify my understanding with pointer arithmetic, especially when accessing struct members. I also had to be careful with properly deleting dynamically allocated memory using delete[] to avoid leaks of memory. 
Another challenge was handling file input and output correctly. One important lesson I learned was taht breaking larger problems into smaller functions makes programming much easier and less stressful. I also learned the importance of testing programs often instead of waiting until a final product. Testing throughout the development process helped me find issues with invalid input, file reading and menu navigation. Another lesson I learned was how useful structs are for organizing related data. Using a "FoodItem" struct made the program cleaner and easier to expand. 

## 6. Future Improvements
- If you had more time, what changes or enhancements would you make?  
Some improvements that I would make going further if I gave myself more time would be improving the menu system by allowing users to delete or edit food items after adding them. Another improvement would be adding more nutrition information such as protein, sugar, sodium and fiber. This would make the calorie tracker more realistic and useful. 
