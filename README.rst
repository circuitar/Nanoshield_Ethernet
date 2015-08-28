Nanoshield_Ethernet
===================

This is an Arduino library to use Circuitar's Ethernet Nanoshield.

This library is fully compatible with the Arduino’s default Ethernet library.

* Source code: https://github.com/circuitar/Nanoshield_Ethernet
* Documentation: http://nanoshield-ethernet.readthedocs.org/
* Reference board: `Ethernet Nanoshield`_ from Circuitar

Extra feature:

* Power save mode with functions: **Ethernet.powerDown()** and **Ethernet.powerUp()**


------
Usage:
------

To adapt your code to use this library replace the include from arduino's Ethernet library to this library. Like so:


//#include <Ethernet.h>

#include <Nanoshield_Ethernet.h>

Examples are included in library but you can also use any example from Arduino's Ethernet library.


--------
Examples
--------
The following examples_ are provided:

* WebClient_ connects to a webpage (e.g. google.com).
* WebClientStatic_ connects to a webpage with manual network values (e.g. IP, Gateway, DNS, MAC).
* WebServer_ creates a simple webserver.

.. _ReadTheDocs: http://nanoshield-ethernet.readthedocs.org
.. _GitHub: https://github.com/circuitar/Nanoshield_Ethernet
.. _`Ethernet Nanoshield`: https://www.circuitar.com.br/en/nanoshields/modules/ethernet/
.. _examples: https://github.com/circuitar/Nanoshield_Ethernet/blob/master/examples/
.. _WebClient: https://github.com/circuitar/Nanoshield_Ethernet/blob/master/examples/WebClient/WebClient.ino
.. _WebClientStatic: https://github.com/circuitar/Nanoshield_LoadCell/blob/master/examples/WebClientStatic/WebClientStatic.ino
.. _WebServer: https://github.com/circuitar/Nanoshield_LoadCell/blob/master/examples/WebServer/WebServer.ino

----

Copyright (c) 2015 Circuitar
All rights reserved.

This software is released under an MIT license. See the attached LICENSE file for details.
