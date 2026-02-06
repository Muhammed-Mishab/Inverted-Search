# Inverted-Search

The objective of this project is to design and implement an Inverted Search system that enables efficient searching of words across multiple text files. The project focuses on building an inverted index that maps words to the documents in which they appear, along with their frequency. This approach significantly improves search performance and demonstrates the fundamentals of information retrieval and data indexing techniques.

# Skills Learned

- Understanding of inverted indexing and search algorithms
- Data structures such as hash tables, linked lists
- File handling and text processing
- Efficient searching and indexing methods

# Tools Used
- C  for implementation
- Linux environment for development and testing
- GCC 
- Text files as input data sources

# Steps

Below are the key steps involved in implementing the Inverted Search system:

1. File Collection and Input

Multiple text files are provided as input to the system. Each file is opened and read line by line to extract words for indexing.

2. Tokenization and Normalization

Text content is tokenized into individual words. Case normalization and removal of special characters are performed to ensure consistent indexing.

3. Index Creation

An inverted index is created where each unique word acts as a key. For every word, a list of documents in which it appears is maintained along with the frequency of occurrence.

4. Search Operation

When a user searches for a word, the system looks up the inverted index and retrieves the list of files containing the word, along with the number of occurrences in each file.

5. Result Display

Search results are displayed in a structured format, showing the filenames and corresponding word counts for quick and efficient retrieval.

Conclusion

This project successfully demonstrates how an Inverted Search system can be used to efficiently index and search large collections of text files. It provides practical insight into data indexing, file processing, and information retrieval concepts, making it highly relevant to search engines, document management systems, and data analysis applications.
