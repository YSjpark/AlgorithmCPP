// 실수 발견!!!! line 수가 == 3 일때만 체크했다가 90점나옴...
// line 이 3 이상이 되도록 >= 3 으로 수정 후 100점

// 후보군이 되는 라인 (가로, 세로, 대각선)들을 모두 Hash 처럼
// 생각해서, 빙고를 놓는 순간, 해당 라인 idx로 가지고 ++ 해준다.

import java.util.Scanner;

public class Main {
	private static Scanner sc;
	private static int[][] map;
	private static int[] mx;
	private static int[] my;
	private static int[] stage;

	public static void scan() {
		map = new int[5][5];

		// 해당 숫자의 map상의 i, j 좌표
		my = new int[26];
		mx = new int[26];
		stage = new int[25];

		int mi, mj, num, si;

		for (mi = 0; mi < 5; mi++) {
			for (mj = 0; mj < 5; mj++) {
				num = sc.nextInt();
				map[mi][mj] = num;
				my[num] = mi;
				mx[num] = mj;
			}
		}
		for (si = 0; si < 25; si++)
			stage[si] = sc.nextInt();
	}

	// sj, si에서 빙고 갯수 세기
	private static int countLine(int si, int sj) {
		int i, j, checked = 0, line = 0;
		// 대각선 체크
		if (si == sj) {
			checked = 0;
			for (i = 0; i < 5; i++)
				if (map[i][i] == -1)
					checked++;
			if (checked == 5)
				line++;
//			System.out.println("ACross " + checked);
		}

		if ((4 - si) == sj) {
			checked = 0;
			for (i = 0; i < 5; i++)
				if (map[4-i][i] == -1)
					checked++;
			if (checked == 5)
				line++;
//			System.out.println("BCross " + checked);
		}

		// 가로 체크
		checked = 0;
		for (j = 0; j < 5; j++)
			if (map[si][j] == -1)
				checked++;
		if (checked == 5)
			line++;
//		System.out.println("Hori " + checked);

		// 세로 체크
		checked = 0;
		for (i = 0; i < 5; i++)
			if (map[i][sj] == -1)
				checked++;
		if (checked == 5)
			line++;
//		System.out.println("Vert " + checked);

		return line;
	}

	static void prtMap() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
				System.out.printf("%d ", map[i][j]);
			System.out.println();
		}
	}

	private static void solve() {
		int selNum, selY, selX, bingo = 0;
		for (int si = 0; si < 25; si++) {
//			System.out.println();
			selNum = stage[si];
			selY = my[selNum];
			selX = mx[selNum];
			map[selY][selX] = -1;
			bingo += countLine(selY, selX);
//			prtMap();

			if (bingo >= 3) {
				System.out.printf("%d", si + 1);
				break;
			}
		}
	}

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		scan();
		solve();
//		System.out.println("end");
	}
}