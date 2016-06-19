/*
 * Copyright (C) 2014 Oliver Degener.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

package org.ollide.rosandroid;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import org.ros.address.InetAddressFactory;
import org.ros.android.RosActivity;
import org.ros.node.NodeConfiguration;
import org.ros.node.NodeMainExecutor;


public class MainActivity extends RosActivity {

    private String myString;
    private SimplePublisherNode node = new SimplePublisherNode();
    private NodeMainExecutor nodeMainExecutor;
    int i = 0;
    String atStartUp;

    public MainActivity() {
        super("RosAndroidExample", "RosAndroidExample");
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    protected void init(NodeMainExecutor nodeMainExecutor) {
        this.nodeMainExecutor = nodeMainExecutor;
        Button startPublisher = (Button) findViewById(R.id.start_publisher);
        Button goForward = (Button) findViewById(R.id.go_forward);
        Button goBackward = (Button) findViewById(R.id.go_backward);
        Button speedUp = (Button) findViewById(R.id.speed_up);
        final Button slowDown = (Button) findViewById(R.id.slow_down);
        Button stopPublisher = (Button) findViewById(R.id.stop_publisher);

        startPublisher.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                startPublisherClicked();
            }
        });

        goForward.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                goForwardClicked();
            }
        });

        goBackward.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                goBackwardClicked();
            }
        });

        speedUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                speedupClicked();
            }

        });

        slowDown.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                slowDownClicked();
            }
        });
        stopPublisher.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                    stopPublisherClicked();
            }
        });
    }

    public void startPublisherClicked() {
        i = 0;
        atStartUp = ("");
        NodeConfiguration nodeConfiguration = NodeConfiguration.newPublic(InetAddressFactory.newNonLoopback().getHostAddress());
        nodeConfiguration.setMasterUri(getMasterUri());
        //this.node.setMyOwnString("bla");
        this.node.setMyOwnInt(i);
        this.node.setMyOwnString(atStartUp);
        this.nodeMainExecutor.execute(this.node, nodeConfiguration);

    }

    public void goForwardClicked() {
        this.node.setMyOwnString("f");
    }

    public void goBackwardClicked() {
        this.node.setMyOwnString("b");
    }

    public void slowDownClicked() {
        i = i-10;
        this.node.setMyOwnInt(i);
    }

    public void speedupClicked() {
        i = i+10;
        this.node.setMyOwnInt(i);
    }

    public void stopPublisherClicked() {
        this.node.setMyOwnString(atStartUp);
        this.node.setMyOwnInt(0);
        this.nodeMainExecutor.shutdown();
    }
}
