clear all
close all

%%Generate and plot a DSB-SC signal
t=1e-4:1e-4:0.12;
fc=200;  %%carrier frequency
c=cos(2*pi*fc*t); %%carrier signal
s=length(t);
x=[zeros(1,s/4) ones(1,s/4) zeros(1,s/4) ones(1,s/4)]; %%message

subplot(3,1,1)
plot(t,x)
ylabel('x(t)')
xlabel('t')
title('Message Signal');

subplot(3,1,2)
plot(t,c)
ylabel('c(t)')
xlabel('t')
title('Carrier Signal');


y=x.*c; %%DSB-SC signal
subplot(3,1,3)
plot(t,y)
ylabel('y(t)')
xlabel('t')
title('DSB-SC Signal');



%%Generate and plot a DSB-TC signal
figure;
t=1e-4:1e-4:0.12;
s=length(t);
fc=200;  %%carrier frequency
K=2;m=0.9;
c=cos(2*pi*fc*t); %%carrier signal
plot(t,fc);
s=length(t);
x=[zeros(1,s/4) ones(1,s/4) zeros(1,s/4) ones(1,s/4)]; %%message

subplot(3,1,1)
plot(t,x)
ylabel('x(t)')
xlabel('t')
title('Message Signal');

subplot(3,1,2)
plot(t,c)
ylabel('c(t)')
xlabel('t')
title('Carrier Signal');


y=(K+m*x).*c; %%DSB-TC signal
subplot(3,1,3)
plot(t,y)
ylabel('y(t)')
xlabel('t')
title('DSB-ST Signal');


%Generate and plot a FM signal
figure;
t=1e-4:1e-4:0.12;
s=length(t);
fc=1e6;  %%carrier frequency
x=[zeros(1,s/4) ones(1,s/4) zeros(1,s/4) ones(1,s/4)]; %%message
kf=100;
subplot(3,1,1)
plot(t,x)
ylabel('x(t)')
xlabel('t')
title('Message Signal');

subplot(3,1,2)
plot(t,c)
ylabel('c(t)')
xlabel('t')
title('Carrier Signal');
fi=fc+kf*x; %%instantaneous frequency for FM plot
y=cos(2*pi*fi.*t);

subplot(3,1,3)
plot(t,y)
ylabel('y(t)')
xlabel('t')
title('FM Signal');

%Generate and plot a PM signal
figure;
t=1e-4:1e-4:0.12;
s=length(t);
fc=1e6;  %%carrier frequency
x=[zeros(1,s/4) ones(1,s/4) zeros(1,s/4) ones(1,s/4)]; %%message
kp=10;
subplot(3,1,1)
plot(t,x)
ylabel('x(t)')
xlabel('t')
title('Message Signal');

subplot(3,1,2)
plot(t,c)
ylabel('c(t)')
xlabel('t')
title('Carrier Signal');
y=cos(2*pi*fc*t+kp*x);

subplot(3,1,3)
plot(t,y)
ylabel('y(t)')
xlabel('t')
title('PM Signal');
