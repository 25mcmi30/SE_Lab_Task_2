# Student Result Processing System

### 1. Modularity
#### 1.1 `student.c / student.h` – Student Data Module
- Defines the `Student` and `StudentDatabase` structures
- Stores student information: ID, name, marks, total, percentage, grade, CGPA
- Provides basic operations for handling student records

#### 1.2 `validation.c / validation.h` – Validation Module
- Validates input data before processing:
  - Checks if student ID is alphanumeric and unique
  - Validates names (alphabetical only)
  - Checks marks are within 0–100
  - Ensures minimum passing criteria for subjects

#### 1.3 `result.c / result.h` – Result Calculation Module
- Calculates total marks and percentage for each student
- Assigns grades based on percentage
- Calculates CGPA based on percentage

#### 1.4 `stats.c / stats.h` – Statistics Module
- Calculates class statistics:
  - Class average percentage
  - Highest and lowest percentages
  - Grade distribution across all students

#### 1.5 `fileio.c / fileio.h` – File Handling Module
- Reads student data from `students.txt`
- Writes formatted results to `Student_Result_Report.txt`
- Ensures proper file operations and error handling

### 2. Quality Characteristics (CO-6)
- **Usability:** Easy-to-run with simple `make` and executable  
- **Efficiency:** Processes up to 100 students optimally with minimal memory overhead  
- **Reusability:** Modules can be reused in other student/result processing projects  
- **Interoperability:** Data can be accessed from other systems by reading/writing standard text files  

### 3. How to Run
1. Open terminal in the project directory  
2. Compile using `make`  
3. Run the program:

```bash
./student_database
```
### 4. Output
When the program is executed a text file named Student_Result_Report.txt is generated listing all student grades and stats.