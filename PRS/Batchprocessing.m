% PID controller example
% 2nd Order Process / IRT005 / 
% O.Figaroa 
%
close all; 
clearvars;                  % Clear all variables
num=[1];                    % numerator
den =[625 50 1];            % denumerator
Gopen=tf(num,den);          % Transfer function open loop
figure(1);                  % Create figure 1 for the step response
step(Gopen);                % step response open loop
grid on                     %
hold on                     % figure 1 on hold for next responses in the same figure
Contr= pidtune(Gopen,'PID');% Tuning Kp, Ki and Kd
%Show parameters obtained by matlab tool
X =('Obtained PID parameters:');
disp(X);
Contr
% Closed loop with Obtained PID
Gclose= feedback(Contr*Gopen,1);
step(Gclose);               %  Step response
% = = = = = = = = = = = = = = = =
% PID parameters modified by User = =
% obtained by command >> pidTuner(Gopen);
%
Contr.Kp=6.902;               % Kp - parameter modified by User
Contr.Ki=0.189;               % Ki - parameter modified by User
Contr.Kd=63.03;              % Kd - parameter modified by User
% Closed loop 
Gclos2= feedback(Contr*Gopen,1);
step(Gclos2);
title(['PID Controller Kp = ',num2str(Contr.Kp),' Ki = ',num2str(Contr.Ki),' Kd = ',num2str(Contr.Kd)]);
legend('Open-loop response','Standard PID response', 'Modified PID response');
pidTuner(Gopen);
