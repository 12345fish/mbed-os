/* NetworkStack
 * Copyright (c) 2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include "mbed.h"
#include "SocketAddress.h"

class NetworkInterface {
public:
    virtual ~NetworkInterface() {};
    NetworkInterface() {}

    /** Get the internally stored IP address
    /return     IP address of the interface or null if not yet connected
    */
    virtual const char *get_ip_address() = 0;
protected:
    friend class Socket;
    friend class UDPSocket;
    friend class TCPSocket;
    friend class TCPServer;
    friend class SocketAddress;
    virtual NetworkStack * get_stack(void) = 0;
};

#endif
