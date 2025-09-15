## CSE3150 Week3 Hw

**Pointers**
We use C style char* arrays in this assignment to store strings. This has us pass addresses to our functions, like addStudent and printStudent, which we then use directly in order to use the entire string. We also use pointers for our updateGPA function, where we have a double* gpaPtr that we dereference in order to insert the new gpa value.

**const**
We use const variable in both printStudent and averageGPA. We use these in the printStudent function because we do not want to modify either the name or gpa that we pass in with a function call. In averageGPA, we make the gpas list we pass in constant because we also do not want  to modify any values within the list, simply collect the values for calculating an average. Moreover, we use const for our output msg's for our try-catch-throw blocks. We do this because we never want to alter our
premade error messages.

**References**
Refernces are used for calling variables directly into functions instead of making a copy of them. It is also commonly used to allow the modifying of the original variable within a function. We use this for int size in "addStudent" so that we can increment size within the function.

**Casting**
There is a single instance of casting in this assignment where we take our returned gpa average and cast it into an int. WE do this so that it is a rounded value, as is specification of the assignment. Is a simple way to avoid potentially unattractive double values when you do not care about non-whole values.

**Exceptions**
We catch two exceptions with the try-catch-throw blocks. The first one is for the addStudent function, where is size exceeds capacity for a given instance we throw an error. This dodges undefined behavior from an out of bound index. We also do this for averageGPA, as we accidentally get undefined behaviour if we try to divide result before size is updated. This would be a division by zero error.

**Control Flow**
To control the menu choices from the user, we use a switch-case statement to make repeated selection easy for the user. If they select the correct option, it will call the respective case and proceed with its designated function. After, it redisplays the menu and the user can select again. If they choose a wrong option, it will default to reprompting the user with the menu. They can quit with the menu as well.
