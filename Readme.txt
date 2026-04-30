# Mini Search Engine (C++)

A simple command-line search engine built in C++ that indexes text files and allows fast keyword-based search using an inverted index.

***********************************************************************************************************

Project Structure

mini-search-engine/
│
├── data/              # Text files to be indexed
├── src/
│   └── main.cpp       # Main source code
└── README.md

***********************************************************************************************************

How to Run

1. Compile the program

g++ -std=c++17 main.cpp -o search
or
g++ filename.cpp   #use the upper one if this doesn't works.


2. Run the program

./search

***********************************************************************************************************

Indexing Files

To index files, provide the **path to the folder** containing your `.txt` files.


Example:

If your `data` folder is inside your project:
> index data

If your folder is located somewhere else (e.g., Documents):

> index <data_folder_location>
replace the  <data_folder_location>  with the actual location of the data folder example. C:\Documents\data\


  # Make sure the folder exists and contains text files.

***********************************************************************************************************

Search Commands

Once indexing is complete, you can search for words:
> search machine
> search machine learning
> search cpp systems

***********************************************************************************************************

## Available Commands


index <folder_path>   → Index all text files in the folder
search <keywords>     → Search for words
exit                  → Exit the program

***********************************************************************************************************

## Features

* Inverted index implementation
* Fast keyword-based search
* Frequency-based ranking (TF)
* Case-insensitive search
* Command-line interface

***********************************************************************************************************

## Notes

* `main.cpp` is located inside the `src/` folder
* Ensure your text files are properly formatted
* Use correct folder paths while indexing
* You can use terminal commands like `ls` (Mac/Linux) or `dir` (Windows) to verify files

***********************************************************************************************************

## What This Project Demonstrates

* File handling in C++
* Use of STL (`unordered_map`, `vector`)
* Basic information retrieval concepts
* Building a simple search engine from scratch

***********************************************************************************************************

## Future Improvements

* Remove punctuation
* Stop-word filtering
* TF-IDF ranking
* Save/load index from file
* GUI or web interface
