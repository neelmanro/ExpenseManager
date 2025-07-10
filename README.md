# PlagiarismChecker  
Author – Neel Manro, manroneel@gmail.com

A simple **Python-based Plagiarism Checker** that compares two essay files by removing stopwords, filtering unique words, and calculating a similarity score using set operations. This tool helps detect copied content with clear percentage-based feedback.

This project is built with beginner-friendly Python concepts like functions, file handling, sets, dictionaries, and conditionals. It runs entirely in the terminal.

---

### 1. Features

- Read and display two essay files  
- Clean and filter words by removing stopwords  
- Count total words and unique words in both files  
- Detect matching and differing words  
- Calculate a similarity score (%)  
- Print a result message (LOW, MEDIUM, or HIGH similarity)

---

### 2. Concepts Used

- Python functions  
- File input/output (`open`, `read`, `with` statement)  
- String manipulation (`split`, `replace`, `lower`)  
- Sets and dictionaries  
- Conditionals and comparisons  
- Basic math and percentage calculation  
- Reusable logic via helper functions

---

### 3. How to Run

1. Clone or download the repo  
2. Add your `.txt` essay files to the same directory  
3. Rename them as `essay_draft.txt` and `copied_draft.txt` (or modify the script filenames)  
4. Run the script:

```bash
python plagiarism_checker.py
