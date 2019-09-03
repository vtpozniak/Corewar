.name		"Kievstoner"
.comment	"Tju - Tak a Tu Sho?"
zjmp %:loop
st r1, 6
loop: live %0
xd: st r16, -20
st r16, -30
st r16, -40
st r16, -50
st r16, -60
st r16, -70
st r16, -75
st r16, -80
st r16, -90
st r16, -100
zjmp %:l1
st r1, 6
l1: live %0
st r16, -110
st r16, -120
st r16, -130
st r16, -140
st r16, -150
st r16, -160
st r16, -170
st r16, -180
st r16, -190
st r16, -200
st r16, -210
st r16, -220
st r16, -230
st r16, -240
st r16, -250
st r16, -260
st r16, -270
st r16, -280
st r16, -290
st r16, -300
zjmp %:l2
st r1, 6
l2: live %0
st r16, -310
st r16, -320
st r16, -330
st r16, -340
st r16, -350
st r16, -360
st r16, -370
st r16, -380
st r16, -390
st r16, -400
st r16, -410
st r16, -420
st r16, -430
st r16, -440
st r16, -450
st r16, -460
st r16, -470
st r16, -480
st r16, -490
zjmp %:l3
st r1, 6
l3: live %0
zjmp %:loop
fork %:xd
#ldi %:loop, 2, 1
ld %0, r2

zjmp %:loop
