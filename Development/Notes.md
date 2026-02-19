# Web Development Using MERN Stack
## Instructor - **Love Babbar** (founder of CodeHelp)
Series - Complete Web Dev using MERN stack (https://www.youtube.com/watch?v=Vi9bxu-M-ag&list=PLDzeHZWIZsTo0wSBcg4-NMIbC0L8evLrD)

### 12th February 2026

**Intoduction and Basics of Web Development**

- **_What is Web?_**

    Web is an entity which lies inside another, bigger entity called the _Internet_, which binds all the resources, data and information together around the world. Sp, web consists of data like text, images, videos, books etc which can be accessed using the internet.  

- **_Websites & Web Apps_**

    The static web pages, which are usually read-only blogs and documents having little or no user inetractions are known as **_Websites_** whereas dynamic content on web pages which allow user interaction and continous changes altogether create a **_Web App_**.

- **_Breakdown of Web Apps_**

    - Frontend / User Interface (UI): The visual layer perceived and interacted with by the user of the web app.
    - Backend / Logic Definition: The layer which holds the logic and fucntionalities (behaviour) of the web app.
    - DataBase / Data Warehouse: The layer which stores and retrieves the data to and from the web app.  

    People who expertise in Frontend are known as FrontEnd Engineers.  
    People who expertise in Backend are known as Backend Engineers.  
    People who expertise in  both Frontend & Backend along with Database Management are known as Full Stack Developers.  

### 14th February 2026 (Valentines Day:)

- **_Network_**

    Network is an entity which consists of a number of devices across the world tied together to share resources and provide connection from one device to another.  

    _Types of Networks:_  

    - LAN: Local Area Network  

        LAN is a network model spread in a small area like a room or a building etc for a smaller number of people & devices.  

    - MAN: Metropolitan Area Network

        MAN is spread throughout entire cities and states connecting a large number of people & devices.  

    - WAN: Wide Area Network

        WAN's spread area crosses countries and continents.  

- **_Internet_**

    The _network of networks_ interconnected together throughout the globe is known as Internet. It is the largest system of millions and billions of devices. It is the superset of the World Wide Web.

- **_World Wide Web_**

    World Wide Web (www) consists of all the resources like documents, photos, videos, blogs and files etc which can be accessed usign the Internet. _www_ is a subset of the Internet.

- **_IP Addresses_**

    To access a device (to share resources and data), we need to have the specific address of that device where it resides in the ineternet. This unique address which is used to identify devices is knwon as an _IP Address_.

    - IPv4

        32-bit address length.  
        Supports ~4.3 million devices.  
        Example: 192.168.1.1.  

    - IPv6

        128-bit address length.  
        Supports ~340 undecillion devices (very huge ~340000000000000000000000000000000000000).  
        Example: 2001:0db8:85a3:0000:0000:8a2e:0370:7334.  

    IPv6 was required because of the growth of number of devices which were going out of range of IPv4 addresses.  

- **_Browsers_**

    Browsers are softwares which are used to access the World Wide Web (Internet).  
    Browsers also use a browser engine to display text, graphic and other content on the web page.  
    Examples: Google Chrome, Mozilla Firefox, Opera etc.

    - **Browser Engines**

        Browser Engines load web pages, interpret the HTML & CSS code and visualize the content on the device screen.  
        Example: Blink, WebKit, Gecko etc.  

    Process:  

    - Request is made by user
    - Browser fetches the HTML from the server
    - Browser engine takes the HTML
    - Interprets the HTML, build structure of page and renders visual content on the screen

- **_Client & Server Model_**

    A device which requests something from the Internet is known as a _Client_.  
    A device which fulfills the requests of a client by sending responses is known as a _Server_.  

- **_DNS & DNR_**

    Whenever a website is requested by a user by it's domain name (like www.google.com), the domain name does not exist exactly how we type on the browser. So, the _Domain Name Resolution (DNR)_ process is done which converts the domain name (website name) to it's server's unique IP Address.  

### 19 February 2026

**What is Internet?**

- **_Addresses_**

    Addresses are needed for sending and recieving information throughout the Internet.  
    For Example: IPv4 & IPv6 Addresses

- **_Client-Server_**

    The system which requests something over the Inetrnet is called a **_Client_**.  
    The system which fulfiils the request of the _client_ is called a **_Server_**.  
    It is not necessary that a client can directly request from a server, there may or may not be mediators.  

- **_Protocol Stack & Protocols_**

    The stack of layers which together make the Internet work are called protocol stack.  
    Protocols like TCP (Transfer Control Protocol) and IP (Internet Protocol) are present in the protocol stack which govern the exchange of information in a standard manner.  

    Some of the most used protocols:  
    - HTTP - HyperText Transfer Protocol
    - HTTPS - HyperText Transfer Protocol Secure
    - FTP - File Transfer Protocol
    - SMTP - Simple Mail Transfer Protocol

- **_Packets, ISPs, Routers, Routing Tables & Requests_**

    The data is transferred over the Internet in small chunks rather than large, whole data files. These small data chunks are known as _packets_. Any data exchange on the Internet is done using data packets.  

    _Packets & requests, when sent by a system to another system, do not directly interact with the system itself but an ISP (Internet Services Provider) acts as a bridge between them which connects the systems together_.  

    ISPs can be of different types, for example if we request for a website (if we try to access a website), the _router_ (a device used to create requests and interact with other systems) first sends the request to the local ISP, which then checks for the requested address in the _Routing Table_ (A table storing indices with keys to a number of IP addresses). If the request matches to one of the records, it redirects the client to the website. But if the request does not match any record in the routing table, the local ISP redirects the request to the NSP (National ISP) and this way, the request bounces multiple times from one ISP to another and reaches the destination.  

**HTML Tags & Categorization**  

A _tag_ is a markup entity used to add _structure, meaning_ or _formatting_ to a webpage.  
Types of Tags:  

- **Structural Tags**: Tags which define the structure of the webpage (these are the skeleton of the web).  
Examples: <code> < html >, < head >, < body >, < header >, < footer >, < section > </code> and so on...
- **Sematic Tags**: Tags which convey some specific meaning to some part of the webpage.  
Example: <code> < main >, < body >, < nav >, < article >, < header >, < footer >, < table >, < tr >, < td >, < img >, < form >, < input > </code> and so on...
- **Formatting Tags**: Tags which format the structure and text on the webpage.  
Example: <code> < s >, < em >, < sub >, < sup >, < pre >, < code >, < strong >, < b >, < u >, < i > </code> and so on...  

**HTML Elements**

HTML elements are basically code enclosed within an opening and closing tag like <code> < body > code < /body > </code>  
Here, < body >< /body > is a HTML element.  

- **Inline Elements**: Elements which take up only enough space to fit it's contents without wasting any other space.  
Example: <code> < span > </code>  
- **Block Elements**: Elements which take up space of a single line whether it's contents fit in completely or partially.  
Example: <code> < div > </code>  