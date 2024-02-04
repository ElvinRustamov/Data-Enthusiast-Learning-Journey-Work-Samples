# Coursera Scraper

This project involves the development of a custom Python scraper designed to extract Coursera course information based on specific keywords. The scraper is encapsulated within a class that features two main functions: one for collecting course URLs and another for gathering detailed course content. The goal is to streamline the data extraction process from Coursera's platform.

Once the course data is gathered, a structured dataset is created in Python, allowing for efficient data manipulation and analysis. The dataset is then subjected to a thorough cleaning process to ensure accuracy and consistency, addressing any irregularities or missing values.

To provide stakeholders with a visually appealing and insightful representation of the collected data, a Power BI dashboard is built. This dashboard acts as a centralized hub for visualizing key metrics, trends, and patterns within the Coursera courses dataset.

The combination of Python for data extraction and cleaning, along with Power BI for data visualization, ensures a robust end-to-end solution for efficiently gathering, processing, and analyzing Coursera course data. This project not only automates the data collection process but also empowers users to make data-driven decisions by presenting a comprehensive overview of Coursera course offerings based on their specified keywords.

Step 1: Import Necessary Libraries
- In Python, start by importing the required libraries, such as requests, BeautifulSoup, time and pandas.

Step 2: Create a Class for Scraping
- Define a class (e.g., Coursera) with functions to gather course URLs and course content. Utilize requests for HTTP requests and BeautifulSoup for HTML parsing.

Step 3: Gather Course URLs
- Implement the course_url_scraper function in the class to scrape course URLs from Coursera search results based on a given keyword.

Step 4: Gather Course Content
- Implement the course_content_scraper function to scrape course content from a specific course URL.

Step 5: Create a Structured Dataset
- Utilize the gathered information to create a structured dataset, possibly a Pandas DataFrame.

Step 6: Clean the Dataset in Python
- Perform data cleaning operations using Pandas or other libraries, based on the dataset's structure and specific requirements.

Step 7: Create a Dashboard in Power BI
- Open Power BI Desktop.
- Load the cleaned dataset.
- Design the dashboard by adding visuals, charts, and tables.
- Customize the layout and appearance as needed.
- Save the Power BI file.
