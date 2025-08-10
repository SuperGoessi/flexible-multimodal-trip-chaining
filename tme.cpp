// tme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdio>
#include "inout.h"
#include "checkFunc.h"
#include "timeexpanded.h"
#include "search.h"
#include "binaryheap.h"
#include "netbuild.h"
#include "test.h"
#include "sepsearch.h"
#include "deleteStation.h"

int main()
{
    // with preselection
    test_data_pre();
    allocate_instances();
    assignPVSearchNet(); // no time assign
    assignPVPTConnNet();
    assignPV2Shop(); // delete
    assignSpeedProfile(5);
    vector<vector<int>> ptData = tm_expanded();
    output_vector(ptData);
    
    assignPTSearchNet(ptData);
    assignPTSearchNet_reverse(ptData);
    assignSimplePTSearchNet(computeAverageTime());
    init_heaps(); 
    assignSta2Shop(4);
    assignSta2Park(4);
/*
    time_t begin, end; // time_t is a datatype to store time values.

    time(&begin); // note time before execution

    vector<vector<int>> population_result;

    for (int m = 0; m < test_data->testDataNum; m++)
    {
        int pvflag1 = 0;

        int startNode = findNewIdx(test_data->idx[m]);
        int endNode = findNewIdx(test_data->idx[m]);
        int startTime = test_data->startTime[m];
        int timeBudget = test_data->timeBudget[m]; // minute
        int activityTime = test_data->activityTime[m];
        int transferBudget = test_data->transferTime[m];
        double densityfactor = test_data->densityFactor[m];

        assign_stp_ap_init(startNode, endNode, startTime, timeBudget * 10000, transferBudget, activityTime * 10000, densityfactor);*/

        
        /*-----------------------------------------bike and car mode---------------------------------------------------------*/
    
        vector<vector<int>> simplifiedResult_walk;
        vector<vector<int>> simplifiedResult_bike;
        vector<vector<int>> simplifiedResult_car;
        for (int j = 1; j < 3; j++)
        {
            pvflag1 = j;
             // single modal
            unimodal_search(startNode, endNode, startTime, pvflag1, 0);
            vector<vector<int>> single_mode = check_shop_single_v(0, pvflag1);
            cout << j << " " << single_mode.size() << endl;
            // selection with
            vector<vector<int>> result2;
            vector<vector<int>> stations = stationPreSelection(pvflag1, 0);
            for (int i = 0; i < stations.size(); i++)
            {
                int startStation = stations[i][0];
                int startNode2 = stations[i][1];

                vector<vector<int>> arr = multimodal_search(startNode, endNode, startNode2, startStation, startTime, timeBudget, pvflag1, 1);
                result2.reserve(result2.size() + arr.size());
                result2.insert(result2.end(), arr.begin(), arr.end());
                arr.clear();

                rest_heaps();
            }/*
            vector<vector<int>> multi_mode = check_shop_v(result2, 1, 0, pvflag1);
            cout << j << " " << multi_mode.size() << endl;
            if (pvflag1 == 1)
                combineResult(single_mode, multi_mode, simplifiedResult_bike);
            if (pvflag1 == 2)
                combineResult(single_mode, multi_mode, simplifiedResult_car);

        }
        */

        /*-----------------------------------------walk mode---------------------------------------------------------*/
    /*
        // walk
        int pvflag2 = 0;
        unimodal_search(startNode, endNode, startTime, pvflag2, 0);
        vector<vector<int>> single_mode_walk = check_shop_single_v(0, pvflag2);
        // walk-PT
        vector<vector<int>> result5;
        vector<vector<int>> walkstations_start = findNerestStations(4, startNode);
        vector<vector<int>> walkstation_end = findNerestStations(4, endNode);


        for (int i = 0; i < walkstations_start.size(); i++)
        {
            int startStation = walkstations_start[i][0];
            int startNode2 = walkstations_start[i][1];

            for (int j = 0; j < walkstation_end.size(); j++)
            {
                int endStation = walkstation_end[j][0];
                int endNode2 = walkstation_end[j][1];

                vector<vector<int>> arr = multimodal_search_diff(startNode, endNode, startNode2, startStation, endNode2, endStation, startTime, timeBudget, 0, 1);

                result5.reserve(result5.size() + arr.size());
                result5.insert(result5.end(), arr.begin(), arr.end());
                arr.clear();

                rest_heaps();
            }
        }

        vector<vector<int>> walk_mode = check_shop_diff_v(result5, 2, 0, pvflag1);
        combineResult_walk(single_mode_walk, walk_mode, simplifiedResult_walk); // check

        vector<int> walk_sta;
        if (simplifiedResult_walk.size() != 0)
        {
            walk_sta = get_sta(simplifiedResult_walk);
        }
        else
        {
            walk_sta.push_back(0);
            walk_sta.push_back(0);
        }

        vector<int> bike_sta;
        if (simplifiedResult_bike.size() != 0)
        {
            bike_sta = get_sta(simplifiedResult_bike);
        }
        else
        {
            bike_sta.push_back(0);
            bike_sta.push_back(0);
        }

        vector<int> car_sta;
        if (simplifiedResult_car.size() != 0)
        {
            car_sta = get_sta(simplifiedResult_car);
        }
        else
        {
            car_sta.push_back(0);
            car_sta.push_back(0);
        }

        vector<int> temp = sumup(walk_sta, bike_sta, car_sta, m, test_data->PC4[m]);
        population_result.push_back(temp);
        reset_initialization();
        for (auto i : temp)
            cout << i << " ";
        cout << endl;
    }
 
    output_data_ptbackward(population_result, 111);
    time(&end); // note time after execution

    double difference = difftime(end, begin);
    printf("time taken for function() %.2lf seconds.\n", difference);
    
    */
    return 0;
}
