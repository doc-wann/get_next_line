# get_next_line

Welcome to the get_next_line development roadmap!

In this wiki page, I intend to show some of my struggles and lore behind the 'beta-versions' that helped me to achieve and understand fully the final result.

I would like to categorize the completion of this project in three different stages: The Understanding, The Developing (and realisation that I had'nt understood anything), and The Fixing;

The Understanding: This was the first part, and I say, the hardest. Maybe I was a little stunned, due to many personal things happening in my life at the time, but nontheless, it was my first time using FDs and the read function. At first, I got really confused: how would I be able to make a function that knew where my read would have stopped reading in its 'previous activation'? After a few tests, I realised that the very core of read already does that. Nice.
I had an idea that, even through mostly unpractical, could solve the problem: all I had to do was to read the whole file, store the data in a static buffer and then use two more static ints to trace and cut the bits that I needed for every posterior activation of the function. Looked clean, and kinda worked. Maybe you can check some of them tests in the BETAS folder, that I'm looking forward to add to the github project page after I finish it properly.

I was happy, thinking that I had done it in one swing. Then I talked to a few of my fellow programmers-human-coders-people and realised that it was a really bad idea. Not only due to the program being a badly optimized mess, but it also was def not going to pass the grading system. As a programmer, I really should RTFM more. It was implied on the very exercise PDF that reading the whole thing and then cutting it into pieces was not allowed. I had to store only the information that was really important on them static buffers.

Now, most of my BETAS were already wasted. I knew how to solve it, but they were wasted. I kinda wanted to do something a little different than most of the flows people had for this project, I saw some people talking about recursive functions, and... I did not, but if you're reading this and willing to do your own version of the code, go ahead! Recursive functions are a nice and edgy way to aproach, and for sure will help you learn how to do it properly. Anyways, I went for the standard loop-n-read structure.

The Developing: Now I had a clear understanding of how that should be done, and it was all a question of mixing and building it up based on my last works. I used some of the LIBFT functions to simplify the code, and you can see most of it on the utils file. I also remastered some of them, to work "better", fitting to the needs of the marvelous GNL.
The base concept of the GNL you see in the master branch is a loop of read, based around a strchr function boolean. While the main string lacks a \n, the function repeats the reading process and concatenates both the static string and the read output. Whenever it is found, the function breaks and splits the main string (with the whole first line) in two: the line to be returned and the 'spare' content, after the '\n'. By doing this, with the remaining content stored in the static string, we're able to keep the function going from there, without losing a single char from the original FD.

By adding a few situational controls, like the return (NULL) in cases where the buffer_size defined is 0 or lesser than 0 (same case as the fd), and cases where the read output is -1, we were able to mostly reduce user-caused-errors. Another fix to be made was to correctly use the free() function, to deallocate the malloc() allocated memory.

A few lines can be saved by turning the mallocs in the function into callocs.

The Fixing: The final part of the project! I'm currently (12/10/22) in this part. It consists in running tests, lots of tests. As the whole project was developed over the course of 1 week, some things might have gone over my head. Another point to mention is that the code was entirely developed in a virtual machine, the so called 42 Workspace... Which is not perfect. Some tests using the Tripoille tester have timed-out, and I'm yet to test'em in a 'real' enviroment. Wish me luck! This was my 42 project experience, hope your's such a amazing discovery as mine ;) GLHF!
