----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 11/21/2020 01:51:50 PM
-- Design Name: 
-- Module Name: vga_sync - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity vga_sync is
	Port (
		clk: in std_logic;
		hsync, vsync: out std_logic;
		red, green, blue: out std_logic_vector (3 downto 0)
	);
end vga_sync;

architecture Behavioral of vga_sync is
	signal hpos: integer range 0 to 800 :=0;
	signal vpos: integer range 0 to 525 :=0;
begin
	process(clk)
	begin
		if (clk'event and clk='1')then
		--Scanning the position
			if(hpos < 800)then
				hpos<=hpos+1;
			else
				hpos<=0;
				if(vpos < 525)then
						vpos<=vpos+1;
					else
						vpos<=0;
				end if;
			end if;
		--Starting the synchronization	
			if(hpos>16 and hpos<112)then
				hsync<='0';
				else
					hsync<='1';
			end if;
			if(vpos>0 and vpos<12)then
				vsync<='0';
				else
					vsync<='1';
			end if;
			--show when rgb signals will be zero
			if((hpos>0 and hpos<408) or (vpos>0 and vpos<42)) then
				red <= (others=>'0');
				green <= (others =>'0');
				blue <= (others => '0');
			end if;
		end if;
	end process;	
end Behavioral;
