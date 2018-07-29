
ot/config and hyperpixel4.dts fragments for different orientations:


framebuffer_width=480
framebuffer_height=800
display_rotate=0


   fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-inverted-x;
		touchscreen-hyperpixel4;
	    };
        };
    };



framebuffer_width=800
framebuffer_height=480
display_rotate=1


    fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-swapped-x-y;
		touchscreen-hyperpixel4;
	    };
        };
    };



framebuffer_width=480
framebuffer_height=800
display_rotate=2

    fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-inverted-y;
		touchscreen-hyperpixel4;
	    };
        };
    };


framebuffer_width=800
framebuffer_height=480
display_rotate=3


    fragment@3 {
        target = <&i2c_gpio>;
        __overlay__ {
            /* needed to avoid dtc warning */
            #address-cells = <1>;
            #size-cells = <0>;
            ft6236: ft6236@5d {
                compatible = "goodix,gt911";
                reg = <0x5d>;
                interrupt-parent = <&gpio>;
                interrupts = <27 2>;
                touchscreen-inverted-x;
                touchscreen-inverted-y;
                touchscreen-swapped-x-y;
                touchscreen-hyperpixel4;
	    };
        };
    };

