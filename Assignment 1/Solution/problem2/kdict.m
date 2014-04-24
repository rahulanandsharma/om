function [Dictionary,output] = kdict(D)
param.L = 3;   % number of elements in each linear combination.
param.K = 25; % number of dictionary elements
param.numIteration = 50; % number of iteration to execute the K-SVD algorithm.
param.errorFlag = 0; % decompose signals until a certain error is reached. do not use fix number of coefficients.
%param.errorGoal = sigma;
param.preserveDCAtom = 0;
param.displayProgress = 1;
param.InitializationMethod =  'DataElements';
[Dictionary,output]  = KSVD(D,param);


end