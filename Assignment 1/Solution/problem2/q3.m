clc 
close all
clear all
param.L = 1;   % number of elements in each linear combination.
param.K = 14; % number of dictionary elements
param.numIteration = 100; % number of iteration to execute the K-SVD algorithm.
%param.errorGoal = sigma;
param.displayProgress = 1;
param.preserveDCAtom = 0;
lol=[];
param.InitializationMethod =  'DataElements';
load data.mat
[Dictionary,output]  = KSVD(D,param);
figure
plot(output.totalerr)
ylabel('Error rate')
xlabel(' No of Iterations')


n=50;
labels=round(random('unif',1,5,n,1));
lol=zeros(200+param.K,2);
lol(1:200,:)=D';
lol1=Dictionary';
labels=zeros(200+param.K,1);
labels(1:200,1)=0;
labels(200:200+param.K,1)=1;
lol(201:200+param.K,:)=lol1;
h1=figure;
h=gscatter(lol(:,1),lol(:,2),labels,'br','xo');
title('Plot of Data points with 14 Dictionary Elements')
xlabel('X Axis');
ylabel('Y Axis');



