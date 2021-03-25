A graph is implement for finding the cheapest flights. 

-------------
Problem: There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price p. Several airliners provide the service for the cities, and there may be multiple flights operated by different airliners between the same pair of cities, also there may be multiple flights operated by same airliner between the same pair of cities.

Now given all the cities and flights, together with the starting city src and the destination dst, your task is to find the lowest cost from src to dst with up to cost w. If there is no such a route, output -1.

Note that you need to pay 5 more units of price for each transfer of flights with different airlines at one city 

------------------
Funtions:
- Add u v p a: Add a flight, which goes from u to v with cost p operated by airline a.

- Delete u v a: Delete all the flights from u to v operated by airline a.

- Request src dst w: A person wishes to book a ticket from src to dst with the overall cost at most w. Print the lowest cost from src to dst with up to cost w. If there is no such a route, output -1.

-----------

Constraints: 

- First line of input: n (number of cities)

- Other line: instruction Add, Delete, Request

- n (number of cities) : integer, 0<n<=100

- City’s id start from 0

- m (number of flights) : integer,0<m<=100000

- p (price of flight) : integer,0<p<=100

- a (number of airlines) : integer,0<a<=10

--------

Example: 

°°°input°°°

3

Add 0 1 4 0

Add 1 2 8 0

Add 1 2 5 1

Request 0 2 20

Request 0 2 10

Delete 1 2 0

Request 0 2 20

°°°output°°°

12

-1

14

-----------

-Date: 12/2020
