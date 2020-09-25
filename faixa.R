library("readxl")
library("latex2exp")
nome<-"faixaluc.xlsx"
pontos<-read_xlsx(nome, col_names = FALSE)
mat<-as.matrix(pontos)
size<-720
eixo<-seq(0, 3600, 5)
#pontos<-pontos[-9]
n<-8
farben<-rainbow(n)
#logs<-matrix(NA,nrow=30,ncol=720)
#snips<-matrix(NA,nrow=30,ncol=200)
#matplot(eixo, pontos, type="p", pch=20, col=farben, ylab="luz", xlab="tempo (s)", ylim=c(0, 100000))
#mat<-t(mat)
j<-1
k<-0
#eixo2<-seq(1, 200)
concs<-c(1, 5, 10, 50, 100, 150, 250, 500)
plot(mat[,1], type="l", xlab="tempo (s)", ylab="luz", col=farben[1], ylim=c(0, 450000), xaxt="no") ##########PLOTS THE CURVES THEMSELVES#########
  for (i in 2:8){
    lines(mat[,i], col=farben[i])
  }
  axis(1, at=seq(0, 500, 100), labels=seq(0, 2500, 500))
  legend("topright", legend=concs, col=farben, lwd=0.6)

for (i in 1:8){
  plot(mat[,i], type="l", xlab="tempo (5s)", ylab="luz", col=farben[i], main=c(concs[i], "uM"), xaxt="no")
  axis(1, at=seq(0, 500, 25))
}

#1: 0-6, 30-70
#5: 0-10, 175-250
#10: 0-12, 225-275
#50: 0-10, 250-300
#100: 0-20, 300-350 
#150: 0-12, 225-275
#250: 0-10, 200-275
#500: 2-20, 200-300

ksubida <- c(coef(lm(mat[1:10,1]~seq(1, 10, 1)))[2], 
            coef(lm(mat[1:11,2]~seq(1, 11, 1)))[2],
            coef(lm(mat[1:13,3]~seq(1, 13, 1)))[2],
            coef(lm(mat[1:11,4]~seq(1, 11, 1)))[2],
            coef(lm(mat[1:21,5]~seq(1, 21, 1)))[2],
            coef(lm(mat[1:13,6]~seq(1, 13, 1)))[2],
            coef(lm(mat[1:11,7]~seq(1, 11, 1)))[2],
            coef(lm(mat[5:21,8]~seq(1, 17, 1)))[2]
            )
#plot(mat[1:21,5], pch=19)
#abline(lm(mat[1:21,5]~seq(1, 21, 1)))

kdescida <-  c(coef(lm(mat[31:71,1]~seq(31, 71, 1)))[2], 
               coef(lm(mat[176:251,2]~seq(176, 251, 1)))[2],
               coef(lm(mat[226:276,3]~seq(226, 276, 1)))[2],
               coef(lm(mat[251:301,4]~seq(251, 301, 1)))[2],
               coef(lm(mat[301:351,5]~seq(301, 351, 1)))[2],
               coef(lm(mat[226:276,6]~seq(226, 276, 1)))[2],
               coef(lm(mat[201:276,7]~seq(201, 276, 1)))[2],
               coef(lm(mat[201:301,8]~seq(201, 301, 1)))[2] 
            )
#scatter.smooth(mat[31:71,1], pch=19)
#abline(lm(mat[31:71,1]~seq(1, 41, 1)), col="red")

#1: 0-6, 30-70
#5: 0-10, 175-250
#10: 0-12, 225-275
#50: 0-10, 250-300
#100: 0-20, 300-350 
#150: 0-12, 225-275
#250: 0-10, 200-275  
#500: 2-20, 200-300
  

matplot(concs, kdescida/-5, pch=19, col=c("blue"), xlab = TeX("concentração de luciferina ($\\mu M$)"),
        ylab=TeX("Vel. inicial ($s^{-1}$)"), main="Velocidade inicial de descida")

matplot(concs, ksubida/5, pch=19, col=c("purple"), xlab = TeX("concentracão de luciferina ($\\mu M$)"),
        ylab=TeX("Vel. inicial ($s^{-1}$)"), main="Velocidade inicial de subida", ylim=c(0, 1400))

#NLS PARA AS VELOCIDADES DE DESCIDA TIRANDO O QUINTO E ÚLTIMO PONTOS, E FIXANDO O (0,0)
X2 <- c(0, concs[c(1:4, 6, 7)])
Y2 <- c(0, kdescida[c(1:4, 6, 7)]/-5)
model2 <- nls(Y2~v/((1+X2/i)+k/X2), start=list(v=60, k=1, i=2), algorithm = "port")
new.data2 <- data.frame(X2 = seq(min(X2),max(X2),len = 500))
matplot(X2, Y2, pch=19, col=c("blue"), xlab = TeX("concentração de luciferina ($\\mu M$)"),
        ylab=TeX("Vel. inicial ($s^{-1}$)"), main="Velocidade inicial de descida")
lines(new.data2$X2, predict(model2, newdata = new.data2))

#NLS PARA AS VELOCIDADES DE SUBIDA, TIRANDO O ÚLTIMO PONTO, FIXANDO O (0,0)
X <- c(0, concs[1:7])
Y <- c(0, ksubida[1:7]/5)
model <- nls(Y~v/((1+X/i)+k/X), start=list(v=2800, k=37, i=111))
new.data <- data.frame(X = seq(min(X),max(X),len = 500))
matplot(X, Y, pch=19, col=c("purple"), xlab = TeX("concentracão de luciferina ($\\mu M$)"),
        ylab=TeX("Vel. inicial ($s^{-1}$)"), main="Velocidade inicial de subida", ylim=c(0, 1400))
lines(new.data$X, predict(model,newdata = new.data))

