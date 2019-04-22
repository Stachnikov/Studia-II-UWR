package com.company;

import java.util.Timer;

public class HowLong extends Timer {
    private long time_start=0;
    private long time_stop=0;

    HowLong(long start, long stop){
        time_start=start;
        time_stop=stop;
    }

    public long Matchtime(){
        return time_stop-time_start;
    }
}
