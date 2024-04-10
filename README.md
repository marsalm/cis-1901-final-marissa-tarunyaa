### CIS 1901 S24 Final Project. 

## Authors
Marissa Almonte and Tarunyaa Sivakumar

## Project Proposal: C++ Chat Application
# Overview
Our project aims to develop a chat application using C++, providing a real-time messaging platform. This application will serve as a learning project to integrate various aspects of C++ programming, including websockets, server-side scripting, and potentially database integration for storing user data and messages. The primary goal is to facilitate understanding of web development topics within the C++ ecosystem and to showcase the application of C++ in creating networked applications.

# Technical Specifications and Libraries
The chat application will be based on a client-server model utilizing sockets for network communication. For the server part, we plan to use POSIX sockets on Unix/Linux or Winsock on Windows to handle networking. The Boost.Asio library, which provides support for network and low-level I/O programming, will be considered to simplify operations and improve portability across platforms.

To support multiple clients and handle asynchronous operations, we'll leverage C++'s multi-threading capabilities, possibly employing the Standard Template Library (STL) for thread management. This approach will ensure that our server can handle multiple connections simultaneously, allowing real-time communication between clients.

# Structure and Features
The application will have a clear separation between the server and client modules. The server will be responsible for accepting connections, handling incoming messages, and broadcasting them to all connected clients. The client module will handle user input, send messages to the server, and display incoming messages from the server.

We plan to implement a basic text-based interface for the chat application. However, exploring a graphical user interface (GUI) using a library like Qt or SFML is also on our radar for future enhancements. This would make the application more user-friendly and accessible to a wider audience.

The project will be structured around several key classes, including:

- A Server class to manage client connections and message broadcasting.
- A Client class to handle user interaction and communication with the server.
- Utility classes for managing messages, users, and possibly persistent storage.

# Development Timeline and Collaboration
The project is estimated to take around 8 weeks to complete, with the first two weeks dedicated to research and planning, including a deep dive into necessary libraries and setting up the development environment. The next three weeks will focus on implementing the core functionality (server-client communication and multi-threading). The following two weeks will be allocated for additional features and testing. The final week will be reserved for bug fixing, documentation, and final touches.

The work will be divided among our group members based on individual strengths and learning goals. Regular meetings will ensure that everyone is on track and facilitate collaboration on challenging parts of the project.

# Conclusion
This chat application project represents an excellent opportunity to apply and enhance our C++ programming skills, especially in areas like networking, multi-threading, and possibly GUI development. By tackling this project, we aim to build a solid foundation for more complex applications and prepare ourselves for professional C++ development roles.
