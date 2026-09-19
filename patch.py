import re

with open('src/cpu_core.v', 'r') as f:
    content = f.read()

# Upgrade PWM to 8-bit
content = content.replace('reg [3:0] pwm_duty;', 'reg [7:0] pwm_duty;')
content = content.replace('reg [3:0] pwm_counter;', 'reg [7:0] pwm_counter;')
content = content.replace('8\'h26: data_rdata = {4\'h0, pwm_duty};', '8\'h26: data_rdata = pwm_duty;')
content = content.replace('8\'h26: pwm_duty <= acc[3:0];', '8\'h26: pwm_duty <= acc;')
content = content.replace('pwm_duty    <= 4\'h0;', 'pwm_duty    <= 8\'h00;')
content = content.replace('pwm_counter <= 4\'h0;', 'pwm_counter <= 8\'h00;')

with open('src/cpu_core.v', 'w') as f:
    f.write(content)

