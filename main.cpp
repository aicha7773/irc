/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:05:50 by kkouaz            #+#    #+#             */
/*   Updated: 2024/04/01 02:21:28 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./server/header.hpp"

// void recieveSignal(int signum)
// {
//     (void)signum;
//     server :: signal = 1;
// }

int main(int ac, char **av)
{
    if(ac != 3)
    {
        std :: cout << "invalid args\n";
        return(1);
    }
    try
    {
        int port = checkPort(av[1]);
        std :: string password = av[2];
        server server(port, password);
        signal(SIGINT, server :: recieveSignal);
        signal(SIGQUIT, server :: recieveSignal);
        server.setup();
        server.start();
    }
    catch(std :: exception &e)
    {
        std :: cerr << e.what();
    }
}
