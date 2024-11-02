<div align="left">

### 42_cursus_philosopher![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<div align="left">
    
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

<nav>
    
### Summary![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<ul>
    <li><a href="#introduction">Introduction</a></li>
    <li><a href="#mandatory-part">Mandatory Part</a></li>
    <li><a href="#code-overview">Code Overview</a></li>
    <li><a href="#organization-and-task-distribution">Organization and Task Distribution</a></li>
    <li><a href="#execution-breakdown">Execution Breakdown</a></li>
    <li><a href="#feedback">Feedback</a></li>
</ul>
</nav>

### Introduction![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="introduction">

<div align="justify">

The Philosopher project simulates the dining philosophers problem, a classic synchronization problem used to illustrate the challenges of resource allocation among concurrent processes. This project uses threads and mutexes to manage the philosophers' actions of eating, thinking, and sleeping while preventing deadlocks and ensuring that no philosopher starves.

</div>
</section>

<div align="left">

### Mandatory Part![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="mandatory-part">

Your Philosopher project must implement the following features:
<ul>
    <li>Each philosopher is represented by a thread.</li>
    <li>Philosophers must alternate between eating, thinking, and sleeping.</li>
    <li>There are as many forks as philosophers, and each philosopher needs two forks to eat.</li>
    <li>Philosophers must pick up the forks one at a time.</li>
    <li>Philosophers must put down both forks after eating and before sleeping.</li>
    <li>Philosophers must not die of starvation.</li>
    <li>All state changes of the philosophers (eating, thinking, sleeping, taking a fork, and dying) must be logged with a timestamp.</li>
    <li>The simulation stops if a philosopher dies.</li>
</ul>
</section>

<div align="left">

### Code Overview![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="code-overview">

<h3>Parsing</h3>
<p>The parsing part of the Philosopher project includes the following files:</p>
<ul>
    <li><code>philo_parsing.c</code>: Functions to parse command line arguments and initialize the simulation parameters.</li>
</ul>

<h3>Memory Management</h3>
<p>The memory management part of the Philosopher project includes the following files:</p>
<ul>
    <li><code>philo_memory_allocation.c</code>: Functions to allocate memory for the philosopher structures and other resources.</li>
    <li><code>philo_memory_liberation.c</code>: Functions to free the allocated memory and ensure no memory leaks.</li>
</ul>

<h3>Action Handling</h3>
<p>The action handling part of the Philosopher project includes the following files:</p>
<ul>
    <li><code>philo_actions.c</code>: Functions that define the actions (eating, thinking, and sleeping) of each philosopher.</li>
    <li><code>philo_routine.c</code>: Functions that define the main routine for each philosopher thread.</li>
    <li><code>philo_survey_routine.c</code>: Functions that monitor the philosophers' states to detect and handle starvation.</li>
</ul>

<h3>Thread Management</h3>
<p>The thread management part of the Philosopher project includes the following files:</p>
<ul>
    <li><code>philo_threads.c</code>: Functions to create, detach, and join philosopher threads.</li>
</ul>

<h3>Utilities</h3>
<p>The utility part of the Philosopher project includes the following files:</p>
<ul>
    <li><code>philo_utils.c</code>: Utility functions for handling time, printing logs, and other helper functions.</li>
    <li><code>philo_error_utils.c</code>: Utility functions for handling errors and printing error messages.</li>
    <li><code>philo_error.c</code>: Functions to handle error scenarios and clean up resources.</li>
</ul>

<h3>Main Execution</h3>
<p>The main execution part of the Philosopher project includes the following file:</p>
<ul>
    <li><code>main.c</code>: The entry point of the program that initializes the simulation and starts the philosopher threads.</li>
</ul>
</section>

<div align="left">

### Organization and Task Distribution![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="organization-and-task-distribution">

In our group, named "the brute and the cunning", we decided to clearly separate our responsibilities. I handled the memory management and action handling, while my partner focused on parsing and thread management. This clear division allowed us to work efficiently and integrate our parts smoothly.

</section>

<div align="left">

### Execution Breakdown![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="execution-breakdown">

For this project, I divided the execution into four main parts:
<ol>
    <li>
        <strong>Memory Management:</strong>
        <p>Allocating and freeing memory efficiently to ensure no leaks occur during the simulation. This part was challenging due to the need to manage multiple dynamic allocations and deallocations.</p>
    </li>
    <li>
        <strong>Action Handling:</strong>
        <p>Defining the actions of eating, thinking, and sleeping for each philosopher. Ensuring that these actions are performed in the correct order and logged accurately.</p>
    </li>
    <li>
        <strong>Thread Management:</strong>
        <p>Creating and managing threads for each philosopher. Ensuring that threads are properly synchronized to avoid deadlocks and race conditions.</p>
    </li>
    <li>
        <strong>Error Handling:</strong>
        <p>Implementing robust error handling mechanisms to gracefully handle any unexpected scenarios. This included validating input parameters and ensuring proper cleanup of resources in case of errors.</p>
    </li>
</ol>
</section>

<div align="left">

### Feedback![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="feedback">

The Philosopher project allows for the mastery of two essential concepts in low-level programming: threads and mutexes. Successfully completing this project primarily hinges on understanding and effectively utilizing these concepts.

For me, having previously worked on the Minishell project, I found this one relatively manageable. To challenge myself further, I focused on enhancing the readability of my code. Although I am not entirely satisfied with the final result, I noticed significant improvements in the syntax and formatting of my code during the writing process. Consequently, the amount of work required for bug fixing, compliance with standards, and code clarification was reduced for this project.

On a personal note, I truly enjoyed working on this project. I find the assignment particularly elegant as it allows for the tackling of a purely computational problem. Certain concepts addressed, such as the management of the timer originating from the creation of UNIX, require an understanding and assimilation of a part of the history of computer development.

</section>
</div>
