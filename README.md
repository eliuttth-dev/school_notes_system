# School Notes System

This C++ program allows you to manage student information and their notes. It reads student data from an input file, calculates the average note for each student, and generates a bulletin containing each student's information and their notes, including the average note. The generated bulletin is written to an output file in plain text format.

## Usage

1. **Input File Format**: 
    - The input file (`student_data.txt`) should contain student information in the following format:
      ```
      [Student Name],[Student ID],[Note1],[Note2],...,[NoteN]
      ```
    - Each line represents data for one student.
    - Fields are separated by commas.
    - The first field is the student's name.
    - The second field is the student's ID.
    - The subsequent fields represent the student's notes (as integers).

2. **Compile**:
    - Compile the program using any C++ compiler. For example:
      ```
      g++ main.cpp -o school_notes
      ```

3. **Run**:
    - Run the compiled executable (`school_notes`).
      ```
      ./school_notes
      ```

4. **Output**:
    - After running the program, a file named `bulletin.txt` will be generated in the current directory.
    - This file contains the bulletin with each student's information and their notes, including the average note.

